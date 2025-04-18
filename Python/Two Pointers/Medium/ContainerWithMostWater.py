# Intuition
'''
'''

# Approach
'''
'''

# Complexity

# - Time complexity:
'''
'''

# - Space complexity:
'''
'''
from typing import List

def maxArea(self, height: List[int]) -> int:
    left, right = 0, len(height)-1
    maxHeight = 0
    while(left < right):
        h = min(height[left], height[right]) * (right-left)
        maxHeight = max(h, maxHeight)

        if(height[left] < height[right]):
            left += 1
        else:
            right -= 1

    return maxHeight