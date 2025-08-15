#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<pair<char, int>>> ntwrk;
unordered_map<char, int> heuristic;
bool found = false;

struct Node {
    int f, g;
    string path;
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

void aStar(char start, char goal) {
    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push({heuristic[start], 0, string(1, start)});

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
            cout << " (Cost: " << current.g << ")\n";
            continue;
        }

        for (auto& [next, cost] : ntwrk[last]) {
            if (current.path.find(next) == string::npos) {
                int newG = current.g + cost;
                int newF = newG + heuristic[next];
                pq.push({newF, newG, current.path + next});
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

    aStar(start, goal);

    if (!found) cout << "No route exists.\n";
    return 0;
}
