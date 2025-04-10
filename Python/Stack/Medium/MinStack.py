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

class MinStack:

    def __init__(self):
        self.list1 = []
        self.list2 = []

    def push(self, val: int) -> None:
        self.list1.append(val)
        if not self.list2 or (self.list2 and val < self.list2[-1]):
            self.list2.append(val)
        else:
            self.list2.append(self.list2[-1])

    def pop(self) -> None:
        self.list1.pop()
        self.list2.pop()

    def top(self) -> int:
        return self.list1[-1]

    def getMin(self) -> int:
        return self.list2[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()