#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find_max_index(string number, int k, int curr_index) {
    int max = number[curr_index];
    int max_index = curr_index;
    for(int i = curr_index; i <= curr_index + k && i < number.size(); i++) {
        if(number[i] > max) {
            max = number[i];
            max_index = i;
        }
        // cout << max_index << "\n";
    }
    return max_index;
}

string solution(string number, int k) {
    string answer = "";
    int number_size = number.size();
    int goal_size = number_size - k;

    int max_index = 0;
    int i = 0;
    for(;;) {
        if(k <= 0 || answer.size() == goal_size) {
            break;
        }
        max_index = find_max_index(number, k, i);
        answer += number[max_index];
        // cout << max_index << "\n";
        k -= max_index - i;
        i = max_index + 1;
        // cout << k << "\n";
    }
    for(; k==0 && answer.size() < goal_size; i++) {
        answer += number[i];
    }
    return answer;
}