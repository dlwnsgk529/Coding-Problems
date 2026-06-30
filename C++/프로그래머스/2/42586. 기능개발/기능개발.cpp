#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int left;
    int curr_days;
    int next_days;
    int count = 0;
    for(int i = 0; i < progresses.size(); i++){
        left = 100 - progresses[i];
        curr_days = ceil((double) left / (double) speeds[i]);
        next_days = 0;
        count++;
        while(next_days <= curr_days && i + 1 < progresses.size()){
            left = 100-progresses[i+1];
            next_days = ceil((double) left / (double) speeds[i + 1]);
            if(next_days <= curr_days){
                count++; i++;
            }
            else{
                break;
            }
        }
        answer.push_back(count);
        count = 0;
    }


    return answer;
}