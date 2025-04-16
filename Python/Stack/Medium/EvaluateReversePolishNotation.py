# Intuition
'''
First thought was to pop the last 2 elements as soon as a valid
operator is reached, and replace them by the correct expression
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

def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        if len(tokens) < 2:
            return int(tokens[0])

        for x in tokens:
            if (x == '+' or x == '-' or x =='*' or x == '/') and len(stack) > 1:
                second = stack.pop()
                first = stack.pop()

                if x == '+':
                    stack.append(first + second)
                elif x == '-':
                    stack.append(first - second)
                elif x == '*':
                    stack.append(first * second)
                elif x == '/':
                    stack.append(int(first / second))
            
            else:
                stack.append(int(x))

        return stack[0]
