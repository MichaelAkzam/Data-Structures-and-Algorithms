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

def isValid(self, s: str) -> bool:
    stack = []

    for p in s:
        if stack and ((p == '}' and stack[-1] == '{') or (p == ')' and stack[-1] == '(') or (p == ']' and stack[-1] == '[')):
            stack.pop()
        else:
            stack.append(p)
    
    return True if not stack else False