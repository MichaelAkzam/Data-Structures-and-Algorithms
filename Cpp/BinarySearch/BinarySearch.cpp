/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/
#include <vector>

int search(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
    }
    return -1;
}