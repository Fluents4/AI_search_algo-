#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> ntwrk;
unordered_map<char, int> heuristic;
bool found = false;

void hillClimb(char start, char goal) {
    string path(1, start);
    char current = start;

    while (true) {
        if (current == goal) {
            found = true;
            for (size_t i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << "\n";
            return;
        }

        if (ntwrk[current].empty()) break;

        char nextNode = '\0';
        int bestH = INT_MAX;
        for (char neighbor : ntwrk[current]) {
            if (path.find(neighbor) == string::npos && heuristic[neighbor] < bestH) {
                bestH = heuristic[neighbor];
                nextNode = neighbor;
            }
        }

        if (nextNode == '\0' || bestH >= heuristic[current]) break;

        path.push_back(nextNode);
        current = nextNode;
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

    hillClimb(start, goal);

    if (!found) cout << "No route exists.\n";
    return 0;
}
