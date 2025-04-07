# Intuition
'''
Solution is straightforward we no complex data structures. Populating the dictionary in the 
specific way found below is the only hardish part to extract the required.
'''

# Approach
'''
We traverse the list, looking for the complement of the current number we are pointing to in a dictionary
we populate after every iteration, where the key is the complement and the value being the index of such. 
If the complement is in the dictionary, meaning we already passed over a number that matches our total sum,
we return the current index alongside the index of the complement found.
'''

# Complexity

# - Time complexity:
'''
O(N) as we need to traverse the given list to populate our dictionary (Beats 100% of solutions on LeetCode)
'''

# - Space complexity:

'''
O(N) as we have a dictionary to populate with up to N elements
'''

from typing import List

def twoSum(self, nums: List[int], target: int) -> List[int]:
    d = {}
    for i in range(len(nums)):
        complement = target - nums[i]
        if complement in d:
            return [i, d[complement]]
        d[nums[i]] = i