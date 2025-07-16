/*
Intuition


Approach


Complexity
- Time complexity: O(logN)

- Space complexity: O(1)

*/

#include <vector>
using std::vector;
// OPTIMAL SOLUTION
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;

    while(l <= r){
        int m = l + (r - l) / 2;
        if(nums[m] == target)
            return m;
        if(nums[m] >= nums[l]){
            if(nums[l] <= target && target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        else{
            if(nums[m] < target && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return -1;
}