#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(vector<int> c : commands) {
        for(int i = c[0] - 1; i < c[1]; i++) {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[c[2]-1]);
        temp.clear();
    }

    return answer;
}