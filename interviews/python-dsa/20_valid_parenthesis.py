class Solution:
    def isValid(self, s: str) -> bool:
        """
        Algorithm intuition:
            - we store a map of parenthesis (closing brackets as key)
            - then we iterate through each character in s
            - if we have a closing bracket as the curr curr and that is at the top of stack we pop
            - in the end if stack is empty, we return true else false
        Time: O(n)
        Space: O(n)
        """
        brackets = {")": "(", "]": "[", "}": "{"}

        stack = []

        for c in s:
            if c in brackets and stack and brackets[c] == stack[-1]:
                stack.pop()
            else:
                stack.append(c)

        return not bool(stack)
