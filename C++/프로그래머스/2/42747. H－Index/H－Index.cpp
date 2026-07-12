#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());

    int index = 0;
    while(index < citations.size() && index + 1 <= citations[index]) {
        // cout << citations[index] << "\n";
        index++;
    }

    if(citations[0] == 0){
        return 0;
    }

    return index;
}