#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> min_hp;
    priority_queue<int> max_hp;
    unordered_map<int,int> deleted_num;

    int string_size;
    string string_num;
    int new_num, curr_num;
    for(string op : operations) {
        if(op[0] == 'I') {
            string_size = op.size();
            string_num = "";
            for(int i = 2; i < string_size; i++){
                string_num += op[i];
            }
            new_num = stoi(string_num);
            max_hp.push(new_num);
            min_hp.push(new_num);
        }
        else if(!min_hp.empty() && op == "D -1") {
            curr_num = min_hp.top();
            while(deleted_num.find(curr_num) != deleted_num.end() && deleted_num[curr_num] > 0) {
                deleted_num[curr_num]--;
                min_hp.pop();
                if(!min_hp.empty()) {
                    curr_num = min_hp.top();
                }
            }
            if(!min_hp.empty()){
                curr_num = min_hp.top();
                deleted_num[curr_num]--;
                min_hp.pop();
            }
        } else if(!max_hp.empty() && op == "D 1") {
            curr_num = max_hp.top();
            while(deleted_num.find(curr_num) != deleted_num.end() && deleted_num[curr_num] < 0) {
                deleted_num[curr_num]++;
                max_hp.pop();
                if(!max_hp.empty()) {
                    curr_num = max_hp.top();
                }
            }
            if(!max_hp.empty()) {
                curr_num = max_hp.top();
                deleted_num[curr_num]++;
                max_hp.pop();
            }
        }
        
    }
    // while(!max_hp.empty()) {
    //     cout << max_hp.top() << "\n";
    //     max_hp.pop();
    // }
    // cout << "---\n";
    // while(!min_hp.empty()) {
    //     cout << min_hp.top() << "\n";
    //     min_hp.pop();
    // }
    int deleted_num_size = deleted_num.size();
    while(!max_hp.empty()) {
        curr_num = max_hp.top();
        if(deleted_num.find(curr_num) != deleted_num.end() && deleted_num[curr_num] < 0) {
            deleted_num[curr_num]++;
            max_hp.pop();
            continue;
        }
        answer.push_back(curr_num);
        break;
    }
    while(!min_hp.empty()) {
        curr_num = min_hp.top();
        if(deleted_num.find(curr_num) != deleted_num.end() && deleted_num[curr_num] > 0) {
            deleted_num[curr_num]--;
            min_hp.pop();
            continue;
        }
        answer.push_back(curr_num);
        break;
    }

    if(answer.empty()){
        return {0,0};
    }

    return answer;
}