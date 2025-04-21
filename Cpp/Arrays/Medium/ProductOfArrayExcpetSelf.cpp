/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/

#include <vector>
// Unoptimal Space Complexity of O(N)
std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> res;
    std::vector<int> forwardPass = {nums[0]};
    std::vector<int> backwardPass = {nums.back()};

    for(int i = 1; i < nums.size(); i++){
        forwardPass.push_back(nums[i]*forwardPass[i-1]);
        backwardPass.push_back(nums[nums.size()-1-i]*backwardPass[i-1]);
    }
    std::reverse(std::begin(backwardPass), std::end(backwardPass));
    res.push_back(backwardPass[1]);

    for(int i = 1; i < nums.size()-1; i++){
        int left = i-1, right = i+1;
        res.push_back(forwardPass[left] * backwardPass[right]);
    }
    res.push_back(forwardPass[nums.size()-2]);

    return res;
}