#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> ntwrk;
bool found = false;
vector<string> visitedPaths;

void dfsWithHistory(string path, char goal) {
    visitedPaths.push_back(path);
    char last = path.back();

    if (last == goal) {
        found = true;
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << "\n";
        return;
    }

    for (char next : ntwrk[last]) {
        if (path.find(next) == string::npos) {
            dfsWithHistory(path + next, goal);
        }
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

    char start = 'S';
    char goal = 'G';

    dfsWithHistory(string(1, start), goal);

    if (!found) cout << "No route exists.\n";

    cout << "\nHistory of explored paths:\n";
    for (auto& p : visitedPaths) {
        for (size_t i = 0; i < p.size(); i++) {
            cout << p[i];
            if (i != p.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }

    return 0;
}
