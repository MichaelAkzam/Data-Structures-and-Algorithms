/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/

#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;

    for(int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if(map.find(complement) != map.end()){
            return {map[complement], i};
        }
        map[nums[i]] = i; 
    }
    return {-1, -1};
}