# Intuition
'''
Fairly straightforward and common way to find duplicates in a list,
so it was easy to get a simple solution running.
Might be trickier for someone that has no prior DSA knowledge and is just starting off
'''

# Approach
'''
We traverse the list and populate our dictionary with keys being the 
numbers in the given list, and the value being anything (in my case just a 1)
to add it to the dictionary. We check beforehand if the key already exists
in our dictionary, and if it does, it means that we have already seen
this number as we traversed the list, meaning it is a duplicate. We return.
'''

# Complexity
# - Time complexity:
'''
O(N) as we have to traverse the whole list in the worst case
'''

# - Space complexity:

'''
O(N) as we have to create and populate up to n elemets in a dictionary
'''

from typing import List

def containsDuplicate(self, nums: List[int]) -> bool:
    d = {}
    for num in nums:
        # if key already exists in dict
        if num in d:
            return True
        d[num] = 1
    
    return False