#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;

    unordered_set<int> found[9];

    int curr_num = N;
    for(int i = 1; i < 9; i++) {
        found[i].insert(curr_num);
        curr_num = curr_num * 10 + N;
    }
    
    for(int i = 2; i < 9; i++) {
        for(int j = 1; j < i; j++) {
            for(int a : found[j]) {
                for(int b : found[i - j]) {
                    found[i].insert(a + b);
                    found[i].insert(a - b);
                    found[i].insert(a * b);
                    if(b != 0)
                        found[i].insert(a / b);
                }
            }
        }
    }

    // for(int i = 1; i < 9; i++) {
    //     for(int a : found[i]) {
    //         cout << a << "\n";
    //     }
    // }

    for(int i = 1; i < 9; i++) {
        if(found[i].find(number) != found[i].end()) {
            answer = i;
            break;
        }
    }

    return answer;
}