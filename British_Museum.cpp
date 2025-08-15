#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> ntwrk;

bool goalTest(const string& path, char goal) {
    return path.back() == goal;
}

vector<string> generateAllPaths(char start) {
    vector<string> paths;
    queue<string> q;
    q.push(string(1, start));

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        char last = current.back();
        paths.push_back(current);
        for (char next : ntwrk[last]) {
            if (current.find(next) == string::npos) {
                q.push(current + next);
            }
        }
    }
    return paths;
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

    vector<string> allStates = generateAllPaths(start);
    bool found = false;

    for (auto& state : allStates) {
        if (goalTest(state, goal)) {
            found = true;
            for (size_t i = 0; i < state.size(); i++) {
                cout << state[i];
                if (i != state.size() - 1) cout << " -> ";
            }
            cout << "\n";
        }
    }

    if (!found) cout << "No route exists.\n";

    return 0;
}
