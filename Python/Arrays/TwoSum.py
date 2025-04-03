# Intuition
'''
'''

# Approach
'''
'''

# Complexity

# - Time complexity:
'''
O(N) as we need to traverse the given list to populate our dictionary (Beats 100% of solutions on LeetCode)
'''

# - Space complexity:

'''
'''

from typing import List

def twoSum(self, nums: List[int], target: int) -> List[int]:
    d = {}
    for i in range(len(nums)):
        complement = target - nums[i]
        if complement in d:
            return [i, d[complement]]
        d[nums[i]] = i