class Solution:
    def removeDuplicates(self, s: str) -> str:
        """
        Algorithm intuition:
            - push to stack only if current character is not top of stack
            - else pop from stack
        Time: O(n)
        Space: O(n)
        """
        stack = []

        for c in s:
            if stack and stack[-1] == c:
                stack.pop()
            else:
                stack.append(c)

        return "".join(stack)
