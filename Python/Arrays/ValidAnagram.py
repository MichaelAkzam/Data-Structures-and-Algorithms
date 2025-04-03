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

from collections import defaultdict

def isAnagram(self, s: str, t: str) -> bool:
    d = defaultdict(int)

    for c in s:
        d[c] += 1

    for c in t:
        d[c] -= 1
        if d[c] == 0:
            del d[c]
    
    return not d
