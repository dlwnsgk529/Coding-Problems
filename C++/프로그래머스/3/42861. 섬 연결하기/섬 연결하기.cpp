#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(vector<int> parent, int curr) {
    if(parent[curr] == curr) return curr;
    else return getParent(parent, parent[curr]);
}

bool sort_costs(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    vector<int> parent(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    sort(costs.begin(), costs.end(), sort_costs);

    int start, end, cost;
    for(vector<int> c : costs) {
        start = getParent(parent, c[0]);
        end = getParent(parent, c[1]);
        cost = c[2];

        if(start != end) {
            answer += cost;
            parent[end] = start;
        }
    }

    return answer;
}