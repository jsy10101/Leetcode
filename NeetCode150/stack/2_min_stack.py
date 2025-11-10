class MinStack:

    def __init__(self):
        self.stack = []
        self.monotonicStack = (
            []
        )  # only adding elements in non-increasing order, skip any elements that break this condition

    def push(self, val: int) -> None:
        self.stack.append(val)

        if self.monotonicStack:
            if val <= self.monotonicStack[-1]:
                self.monotonicStack.append(val)
        else:
            self.monotonicStack.append(val)

    def pop(self) -> None:
        if self.monotonicStack and self.stack[-1] == self.monotonicStack[-1]:
            self.monotonicStack.pop()

        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.monotonicStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

# stack = [-2, 0
# monotonicStack = [-2
# -> -3,
# -> 0
# -> -2
