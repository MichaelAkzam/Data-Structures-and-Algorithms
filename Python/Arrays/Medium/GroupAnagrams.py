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

def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    d = {}

    for i in range(len(strs)):
        sortedWord = ''.join(sorted(strs[i]))
        if sortedWord in d:
            d[sortedWord].append(strs[i])
        else:
            d[sortedWord] = [strs[i]]

    return list(d.values())


# Defaultdict approach
from collections import defaultdict

def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    d = defaultdict(list)

    for word in strs:
        sortedWord = ''.join(sorted(word))
        d[sortedWord].append(word)

    return list(d.values())