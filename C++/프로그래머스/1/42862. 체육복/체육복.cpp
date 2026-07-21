#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> count(n, 1);

    int lost_end = lost.size(), reserve_end = reserve.size();
    for(int i = 0; i < lost_end; i ++) {
        count[lost[i] - 1]--;
    }
    for(int i = 0; i < reserve_end; i++) {
        count[reserve[i]-1]++;
    }
    // for(int i = 0; i < n; i++) {
    //     cout << count[i] << " ";
    // }
    // cout << "\n";

    for(int i = 0; i < n - 1; i++) {
        if(count[i] == 0) {
            if(count[i+1] > 1) {
                count[i]++;
                count[i+1]--;
            }
        } else if(count[i] > 1) {
            if(count[i+1] == 0) {
                count[i]--;
                count[i+1]++;
            }
        }
    }

    answer = n;
    for(int i = 0; i < n; i++) {
        // cout << count[i] << " ";
        if(count[i] == 0) {
            answer--;
        }
    }
    // cout << "\n";

    return answer;
}