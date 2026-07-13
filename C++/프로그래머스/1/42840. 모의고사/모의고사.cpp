#include <string>
#include <vector>

using namespace std;

#define FIRST 5
#define SECOND 8
#define THIRD 10

vector<int> first = {1, 2, 3, 4, 5};
vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> counts(3);

    int first_index = 0;
    int second_index = 0;
    int third_index = 0;
    int curr_count, max_count = 0;
    for(int a : answers) {
        if(a == first[first_index]){
            ++counts[0];
        }
        if(a == second[second_index]) {
            ++counts[1];
        }
        if(a == third[third_index]) {
            ++counts[2];
        }

        for(int c : counts) {
            if(c > max_count) {
                max_count = c;
            }
        }
        first_index = (first_index + 1) % FIRST;
        second_index = (second_index + 1) % SECOND;
        third_index = (third_index + 1) % THIRD;
    }
    vector<int> answer;

    for(int i = 0; i < 3; i++) {
        if(max_count == counts[i]) {
            answer.push_back(i+1);
        }
    }
    return answer;
}