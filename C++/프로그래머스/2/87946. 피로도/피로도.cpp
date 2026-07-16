#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void explore(int k, int curr_count, int& max_count, vector<vector<int>> dungeons, vector<bool> visited) {
    max_count = max(curr_count, max_count);

    for(int i = 0; i < dungeons.size(); i++) {
        if(!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            explore(k - dungeons[i][1], curr_count + 1, max_count, dungeons, visited);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visited(dungeons.size(), false);
    explore(k, 0, answer, dungeons, visited);

    return answer;
}