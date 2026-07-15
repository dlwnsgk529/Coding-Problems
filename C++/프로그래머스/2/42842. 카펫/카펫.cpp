#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int yellow_h = 1;
    int yellow_w = yellow;

    int brown_h, brown_w;
    while(yellow_w >= yellow_h){
        brown_h = yellow_h + 2;
        brown_w = yellow_w + 2;
        if(brown_h * brown_w - yellow == brown){
            if(brown_h > brown_w) return {brown_h, brown_w};
            else return {brown_w, brown_h};
        }

        yellow_h++;
        while(yellow % yellow_h != 0){
            yellow_h++;
        }
        yellow_w = yellow/yellow_h;
        // cout << yellow_h << " " << yellow_w << "\n";
    }

    return answer;
}