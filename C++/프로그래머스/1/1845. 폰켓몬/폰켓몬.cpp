#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int total_num = nums.size();

    int take_num = total_num/2;

    unordered_set<int> types;
    for(int num : nums){
        types.insert(num);
    }

    int types_num = types.size();

    if(types_num < take_num){
        return types_num;
    }
    else{
        return take_num;
    }
}