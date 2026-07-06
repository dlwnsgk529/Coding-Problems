#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int arr_size = prices.size();
    vector<int> answer(arr_size);
    stack<int> s;
    
    for(int i = 0; i < arr_size; i++) {
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = arr_size - 1 -s.top();
        s.pop();
    }
    return answer;
}