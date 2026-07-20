#include <string>
#include <vector>

using namespace std;

string dict = "AEIOU";

bool dfs(string curr_word, string final_word, int& count) {
    // cout << curr_word << "\n";
    if(curr_word == final_word) {
        // cout << count << "\n" << curr_word << " " << final_word << "\n"; 
        return true;};
    if(curr_word.size() == 5) {
        return false;
    }
    bool found = false;
    for(int i = 0; i < 5; i++) {
        found = dfs(curr_word + dict[i], final_word, ++count);
        if(found) {
            return true;
        }
    }
    return false;
}

int solution(string word) {
    int answer = 0;
    dfs("", word, answer);
    return answer;
}