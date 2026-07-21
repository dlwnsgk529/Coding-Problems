#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;

    int min_move = name.size() - 1;
    for(int i = 0; i < name.size(); i++) {
        answer += min(name[i] - 'A', 'A' + 26 - name[i]);

        int move_right = i + 1;
        while(move_right < name.size() && name[move_right] == 'A') {
            move_right++;
        }
        min_move = min(min_move, min<int>( i + i + name.size() - move_right, i + name.size() - move_right + name.size() - move_right));
    }

    return answer + min_move;
}