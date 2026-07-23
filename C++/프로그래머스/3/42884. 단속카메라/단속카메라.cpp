#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sort_routes(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), sort_routes);

    // for(int i = 0; i < routes.size(); i++) {
    //     cout << routes[i][0] << " " << routes[i][1] << "\n"; 
    // }


    int place_pos = -30001;
    int enter, exit;
    for(int i = 0; i < routes.size(); i++) {
        enter = routes[i][0];
        exit = routes[i][1];

        if(enter > place_pos) {
            place_pos = exit;
            answer++;
        }
    }

    return answer;
}