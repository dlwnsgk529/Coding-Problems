#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> sorted_p;
    queue<int> q;

    for(int p : priorities) {
        sorted_p.push_back(p);
        q.push(p);
    }
    sort(sorted_p.begin(), sorted_p.end());

    int curr_index = sorted_p.size() - 1;
    int curr_num;
    while(!q.empty()) {
        curr_num = q.front();
        q.pop();
        location--;
        // cout << sorted_p[curr_index] << " : " << curr_num << "\n";
        // cout << location << "\n";
        if(curr_num == sorted_p[curr_index]) {
            curr_index--;
            answer++;
            if(location < 0){
                return answer;
            }
        } else {
            q.push(curr_num);
            if(location < 0) {
                location = q.size() - 1;
            }
        }
    }


    return answer;
}