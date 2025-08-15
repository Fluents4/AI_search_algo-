#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> ntwrk;
bool found = false;

void dfsAllPaths(string path, char goal) {
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
            dfsAllPaths(path + next, goal);
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

    dfsAllPaths(string(1, start), goal);

    if (!found) cout << "No route exists.\n";
    return 0;
}
