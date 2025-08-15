#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<pair<char, int>>> ntwrk;
unordered_map<char, int> heuristic;
bool found = false;

struct Node {
    int cost;
    string path;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

void branchAndBound(char start, char goal) {
    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push({heuristic[start], string(1, start)});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        char last = current.path.back();

        if (last == goal) {
            found = true;
            for (size_t i = 0; i < current.path.size(); i++) {
                cout << current.path[i];
                if (i != current.path.size() - 1) cout << " -> ";
            }
            cout << " (Estimated Cost: " << current.cost << ")\n";
            continue;
        }

        int actualCostSoFar = 0;
        for (size_t i = 0; i < current.path.size() - 1; i++) {
            char u = current.path[i];
            char v = current.path[i + 1];
            for (auto& [n, c] : ntwrk[u]) {
                if (n == v) {
                    actualCostSoFar += c;
                    break;
                }
            }
        }

        for (auto& [next, c] : ntwrk[last]) {
            if (current.path.find(next) == string::npos) {
                int newCost = actualCostSoFar + c + heuristic[next];
                pq.push({newCost, current.path + next});
            }
        }
    }
}

int main() {
    ntwrk['S'] = {{'A', 1}, {'B', 2}};
    ntwrk['A'] = {{'D', 4}};
    ntwrk['B'] = {{'A', 2}, {'C', 5}};
    ntwrk['C'] = {{'E', 2}};
    ntwrk['D'] = {{'G', 1}};
    ntwrk['E'] = {};
    ntwrk['G'] = {};

    heuristic['S'] = 7;
    heuristic['A'] = 6;
    heuristic['B'] = 5;
    heuristic['C'] = 4;
    heuristic['D'] = 1;
    heuristic['E'] = 2;
    heuristic['G'] = 0;

    char start = 'S';
    char goal = 'G';

    branchAndBound(start, goal);

    if (!found) cout << "No route exists.\n";
    return 0;
}
