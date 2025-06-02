/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/

// Non-working solution
#include <algorithm>
#include <vector>
using std::vector;


bool arraySorted(int first, int last) {
    if(first <= last)
        return true;
    return false;
}

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    int smallest = 5001;
    while(l <= r){
        int m = (l + r) / 2;
        if(arraySorted(nums[l], nums[m])){
            smallest = std::min(smallest, nums[l]);
            l = m + 1;
        }
        else{
            smallest = std::min(smallest, nums[m+1]);
            r = m - 1;
        }
    }

    return smallest;
}

// OPTIMAL WORKING SOLUTION
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    int smallest = 5001;

    while(l <= r){
        int m = l + (r - l) / 2;
        if(nums[l] < nums[r]){
            smallest = std::min(smallest, nums[l]);
        }
        smallest = std::min(smallest, nums[m]);
        if(nums[m] >= nums[l])
            l = m + 1;
        else
            r = m - 1;
    }
    return smallest;
}
