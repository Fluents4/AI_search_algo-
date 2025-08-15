#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> ntwrk;
vector<vector<char>> correctPaths; 

void oracleSearch(char start, char goal) {
    for (auto& path : correctPaths) {
        if (path.front() == start && path.back() == goal) {
            for (size_t i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << "\n";
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

    correctPaths = {
        {'S', 'A', 'D', 'G'},
        {'S', 'B', 'A', 'D', 'G'}
    };

    char start = 'S';
    char goal = 'G';

    oracleSearch(start, goal);

    return 0;
}
