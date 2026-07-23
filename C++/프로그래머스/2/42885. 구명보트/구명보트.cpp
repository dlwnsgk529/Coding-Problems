#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int r = people.size() - 1, l = 0;

    while(r > l) {
        if(people[r] + people[l] <= limit) {
            answer++;
            r--; l++;
        } else {
            answer++;
            r--;
        }
    }
    if(r == l) answer++;

    return answer;
}