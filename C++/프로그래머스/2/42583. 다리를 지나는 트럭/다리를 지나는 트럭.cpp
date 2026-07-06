#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    for(int i = 0; i < bridge_length; i++){
        q.push(0);
    }
    int curr_weight = 0;
    int curr_index = 0;
    while(curr_index < truck_weights.size()) {
        curr_weight -= q.front();
        q.pop();
        answer++;
        if(curr_weight + truck_weights[curr_index] <= weight){
            q.push(truck_weights[curr_index]);
            curr_weight += truck_weights[curr_index];
            curr_index++;
        } else {
            q.push(0);
        }
    }
    while(curr_weight > 0){
        curr_weight -= q.front();
        q.pop();
        answer++;
    }
    
    return answer;
}