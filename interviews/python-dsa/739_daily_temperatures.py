class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        """
        Algorithm intuition:
            - initialize an answer list with length n (n = len(temperatures))
            - we then maintain a monotonic non-increasing stack
            - essentially we need to find the next warmer day
            - the purpose of stack is to "stack" colder days in succession until we find a warmer day
            - if we do this, then we can store the index of successive colder days on stack
                - once we have a warmer day, we pop until it not the warmest day
                - in the process, we can populate the ans variable with the distance
                    - which is current warmer day index (i) - top of stack index
        Time: O(n)
        Space: O(n)
        """
        stack = []
        n = len(temperatures)
        ans = [0] * n

        for i in range(n):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                j = stack.pop()
                ans[j] = i - j
            stack.append(i)

        return ans
