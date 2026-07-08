#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i : scoville){
        pq.push(i);
    }

    int num1, num2, new_num;
    // cout << pq.top() << "\n";
    while(pq.size() > 1 && pq.top() < K) {
        num1 = pq.top(); pq.pop();
        num2 = pq.top(); pq.pop();
        new_num = num1 + num2 * 2;
        pq.push(new_num);
        answer++;
    }
    
    if(pq.top() < K){
        return -1;
    }

    return answer;
}