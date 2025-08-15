#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> ntwrk;
bool found = false;

void dfsFromNode(string path, char goal, unordered_set<string>& usedEdges) {
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
        string e1 = string(1, last) + next;
        string e2 = string(1, next) + last;
        if (!usedEdges.count(e1) && !usedEdges.count(e2)) {
            usedEdges.insert(e1);
            usedEdges.insert(e2);
            dfsFromNode(path + next, goal, usedEdges);
            usedEdges.erase(e1);
            usedEdges.erase(e2);
        }
    }
}

void bfsDfsMix(char start, char goal) {
    queue<char> q;
    unordered_set<char> visitedBFS;
    q.push(start);
    visitedBFS.insert(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();

        unordered_set<string> usedEdges;
        dfsFromNode(string(1, node), goal, usedEdges);

        for (char next : ntwrk[node]) {
            if (!visitedBFS.count(next)) {
                q.push(next);
                visitedBFS.insert(next);
            }
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

    bfsDfsMix(start, goal);

    if (!found) cout << "No route exists.\n";
    return 0;
}
