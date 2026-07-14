#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

using namespace std;

set<int> comb_number;

void make_combination(string curr, string other) {
    if(curr != "") {
        comb_number.insert(stoi(curr));
        // cout << curr << "\n";
    }

    for(int i = 0; i < other.size(); i++ ){
        make_combination(curr + other[i], other.substr(0,i) + other.substr(i+1));
    }
}

bool is_prime(int number) {
    int end_num = sqrt(number);

    if(number == 1 || number == 0) return false;
    // cout << number << " : ";
    
    for(int i = 2; i <= end_num; i++) {
        if(number % i == 0){
            // cout << "failed \n";
            return false;
        }
    }
    // cout << number << "\n";
    return true;
}

int solution(string numbers) {
    int answer = 0;

    make_combination("", numbers);
    // for(string n : string_comb_number) {
    //     cout << n << "\n";
    // }
    for(int n : comb_number) {
        if(is_prime(n)) answer++;
    }

    return answer;
}