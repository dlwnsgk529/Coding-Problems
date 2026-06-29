#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> hash_clothes;

    for(auto& cloth : clothes){
        hash_clothes[cloth[1]]++;
    }

    int answer = 1;
    int num_types = hash_clothes.size();
    for(auto& [cloth_type, cloth_count] : hash_clothes){
        answer *= (cloth_count+1);
        // cout << cloth_count << "\n";
    }

    return --answer;
}