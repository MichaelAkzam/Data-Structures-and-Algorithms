/*
Intuition
    The simple way to approach this problem is to just traverse the array and check if each element matches
    the target element, and return that index. The above would be an O(N) solution, and we could do better.
    As the array is sorted in ascending order, a neat trick would be to always look at the middle element and
    check if that middle element is smaller, larger or equal to our target. If it is equal, then we just return
    that element, if it is smaller or larger, then we technically can eliminate one half of the array we are traversing,
    making it much more efficient, with a time complexity of O(logN).

Approach
    Get the middle index, and compare the number that falls under it to the target. If it is smaller, than narrow
    the search to the left-hand side of the middle element, and if it is larger, than narrow it to the right-hand side
    of the given array. Repeat these steps until the element we are currently sitting at matches our target.


Complexity
- Time complexity: O(logN)

- Space complexity: O(1)

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