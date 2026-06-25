#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> part;

    for(auto& name : completion){
        part[name]++;
    }

    for(auto& name : participant){
        part[name]--;
        // cout << name << " " << part[name] << "\n";
        if (part[name] < 0) {
            return name;
        }
    }
}