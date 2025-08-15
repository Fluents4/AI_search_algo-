#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<pair<char, int>>> ntwrk;
bool found = false;

void branchAndBound(char start, char goal) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    pq.push({0, string(1, start)});

    while (!pq.empty()) {
        auto [cost, path] = pq.top();
        pq.pop();

        char last = path.back();

        if (last == goal) {
            found = true;
            for (size_t i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << " (Cost: " << cost << ")\n";
            continue;
        }

        for (auto& [next, edgeCost] : ntwrk[last]) {
            if (path.find(next) == string::npos) {
                pq.push({cost + edgeCost, path + next});
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

    char start = 'S';
    char goal = 'G';

    branchAndBound(start, goal);

    if (!found) cout << "No route exists.\n";
    return 0;
}
