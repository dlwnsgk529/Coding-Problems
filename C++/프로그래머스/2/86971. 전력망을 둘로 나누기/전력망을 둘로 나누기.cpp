#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int bfs(int v1, int v2, int n, vector<vector<int>> tree) {
    vector<bool> visited(n, false);
    queue<int> to_visit;
    int count = 0;

    visited[v1] = true;
    visited[v2] = true;
    to_visit.push(v2);
    count++;

    vector<int> curr_branch;
        
    while(!to_visit.empty()) {
        curr_branch = tree[to_visit.front()];
        to_visit.pop();
        // cout << v2 << "\n";
        // cout << to_visit.front();
        for(int c : curr_branch) {
            if(visited[c]) {
                // cout << c <<" ";
                continue;
            }
            to_visit.push(c);
            visited[c] = true;
            count++;
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n + 1;

    vector<vector<int>> tree(n);


    for(vector<int> wire : wires) {
        tree[wire[0] - 1].push_back(wire[1] - 1);
        tree[wire[1] - 1].push_back(wire[0] - 1);
    }

    int count;
    for(vector<int> wire : wires) {
        count = bfs(wire[0] -1, wire[1] -1, n, tree);

        answer = min(answer, abs(n - (2 * count)));
    }

    return answer;
}