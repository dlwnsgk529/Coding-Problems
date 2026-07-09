#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_string_numbers(const string& a, const string& b) {
    string a_tmp = "";
    string b_tmp = "";
    if(a[0] == b[0]) {
        a_tmp = a + b;
        b_tmp = b + a;
        return a_tmp > b_tmp;
    }

    return a[0] > b[0];
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> string_numbers;
    int numbers_size = numbers.size();
    for(int n : numbers) {
        string_numbers.push_back(to_string(n));
    }
    sort(string_numbers.begin(), string_numbers.end(), compare_string_numbers);
    
    for(string s : string_numbers) {
        answer += s;
    }
    if(answer[0] == '0') {
        return "0";
    }

    return answer;
}