#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> hash_phone_book;
    for(auto& phone_num : phone_book) hash_phone_book[phone_num] = phone_num.size();

    for(auto& phone_num : phone_book){
        string search_num = "";
        int curr_size = phone_num.size();
        for(char num : phone_num){
            search_num += num;
            if(hash_phone_book.find(search_num) != hash_phone_book.end() && curr_size != hash_phone_book[search_num]){
                return false;
            }
        }
    }

    return true;
}