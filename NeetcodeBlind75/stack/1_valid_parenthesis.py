class Solution:
    def isValid(self, s: str) -> bool:
        """
        Algorithm intuition:
            - create a hash map of opening bracket and closing bracket
            - push all the opening brackets to stack
            - if current is closing bracket and corresponding value is not closing bracket of same type return false, else pop
            - in the end if stack is empty return true else false
        Time: O(n)
        Space: O(1)
        """
        brackets = {")": "(", "]": "[", "}": "{"}

        stack = []

        for br in s:
            if br in brackets:
                if stack and stack[-1] == brackets[br]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(br)

        return True if not stack else False
