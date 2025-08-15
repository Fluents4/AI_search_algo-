#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> ntwrk;

void bfsAllPaths(char start, char goal) {
    queue<string> q;
    q.push(string(1, start));
    bool found = false;

    while (!q.empty()) {
        string path = q.front();
        q.pop();
        char last = path.back();

        if (last == goal) {
            found = true;
            for (size_t i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << "\n";
        }

        for (char next : ntwrk[last]) {
            if (path.find(next) == string::npos) {
                q.push(path + next);
            }
        }
    }

    if (!found) cout << "No route exists.\n";
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

    bfsAllPaths(start, goal);

    return 0;
}
