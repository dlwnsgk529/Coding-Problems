#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev_num = -1;
    
    for(int n : arr){
        if(prev_num == n) continue;

        answer.push_back(n);
        prev_num = n;
    }
    

    return answer;
}