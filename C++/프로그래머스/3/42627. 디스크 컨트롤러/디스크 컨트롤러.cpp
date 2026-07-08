#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
    int jobs_size = jobs.size();
    int current_time = 0, answer_time = 0;
    int start_time;
    vector<int> proc;
    for(int i = 0; i < jobs_size; i++){
        if(pq.empty() && jobs[i][0] > current_time){
            current_time = jobs[i][0];
        }
        while(i < jobs_size && jobs[i][0] <= current_time) {
            pq.push({jobs[i][1], jobs[i][0], i});
            i++;
        }
        i--;
        
        if(!pq.empty()) {
            proc = pq.top();
            pq.pop();
            current_time += proc[0];
            answer_time += (current_time - proc[1]);
        }
    }
    while(!pq.empty()) {
        proc = pq.top(); pq.pop();
        current_time += proc[0];
        answer_time += (current_time - proc[1]);
    }
    answer_time /= jobs_size;

    return answer_time;
}