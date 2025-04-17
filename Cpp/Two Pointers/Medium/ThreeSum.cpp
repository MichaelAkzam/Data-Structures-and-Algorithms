/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size()-2; i++){
        // if nums[i] is positive that means the sum can never be = 0
        if(nums[i] > 0)
            break;
        // prevents duplicate 2-pointer search on element already computed
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        
        int left = i+1, right = nums.size()-1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0){
                res.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                // prevents finding duplicate values after finding 0-sum (performing a left only check is fine)
                while(left < right && nums[left] == nums[left-1]){
                    left++;
                }
            }
            else if(sum < 0){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return res;
}