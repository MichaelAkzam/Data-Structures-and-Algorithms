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

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in d:
                return [i, d[complement]]
            d[nums[i]] = i