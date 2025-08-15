#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> ntwrk;
unordered_map<char, int> heuristic;
bool found = false;

void beamSearchWithHistory(char start, char goal, int beamWidth) {
    vector<string> frontier = {string(1, start)};
    unordered_set<char> visited;

    while (!frontier.empty()) {
        vector<string> newFrontier;

        for (auto& path : frontier) {
            char last = path.back();
            visited.insert(last);

            if (last == goal) {
                found = true;
                for (size_t i = 0; i < path.size(); i++) {
                    cout << path[i];
                    if (i != path.size() - 1) cout << " -> ";
                }
                cout << "\n";
            }

            for (char next : ntwrk[last]) {
                if (!visited.count(next) && path.find(next) == string::npos) {
                    newFrontier.push_back(path + next);
                }
            }
        }

        sort(newFrontier.begin(), newFrontier.end(),
             [&](const string& a, const string& b) {
                 return heuristic[a.back()] < heuristic[b.back()];
             });

        if ((int)newFrontier.size() > beamWidth)
            newFrontier.resize(beamWidth);

        frontier = newFrontier;
    }
}

int main() {
    ntwrk['S'] = {'A', 'B'};
    ntwrk['A'] = {'D'};
    ntwrk['B'] = {'A', 'C'};
    ntwrk['C'] = {'E'};
    ntwrk['D'] = {'G'};
    ntwrk['E'] = {};
    ntwrk['G'] = {};

    heuristic['S'] = 6;
    heuristic['A'] = 4;
    heuristic['B'] = 5;
    heuristic['C'] = 3;
    heuristic['D'] = 1;
    heuristic['E'] = 2;
    heuristic['G'] = 0;

    char start = 'S';
    char goal = 'G';
    int beamWidth = 2;

    beamSearchWithHistory(start, goal, beamWidth);

    if (!found) cout << "No route exists.\n";
    return 0;
}
