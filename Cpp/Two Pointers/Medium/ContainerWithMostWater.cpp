/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/
#include <vector>

int maxArea(std::vector<int>& height) {
    int left = 0, right = height.size()-1;
    int maxHeight = 0;

    while(left < right){
        int h = std::min(height[left], height[right]) * (right - left);
        maxHeight = std::max(h, maxHeight);

        if(height[left] < height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return maxHeight;
}