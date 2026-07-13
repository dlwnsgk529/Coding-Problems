#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w_min = 0, h_min = 0;

    int w1, h1, w2, h2;
    for(vector<int> s : sizes) {
        w1 = s[0]; h1 = s[1];
        w2 = s[1]; h2 = s[0];

        if(w1 < w_min) {
            w1 = w_min;
        }
        if(w2 < w_min) {
            w2 = w_min;
        }
        if(h1 < h_min) {
            h1 = h_min;
        }
        if(h2 < h_min) {
            h2 = h_min;
        }

        if(w1 * h1 < w2 * h2) {
            w_min = w1;
            h_min = h1;
        } else {
            w_min = w2;
            h_min = h2;
        }

        // cout << w2 << " " << h2 << "\n";
        // cout << s[0] << " " << s[1] << "\n";
    }

    return answer = w_min * h_min;
}