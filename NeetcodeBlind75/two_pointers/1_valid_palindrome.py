class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        Algorithm intuition:
            - we can use a two pointer approach
            - start with left and right index pointer
            - check if s[left] == s[right]
                - if at any time false then return False
            - if element at index is not alphanumber we increase just the left or right pointer accordingly
        Time: O(n)
        Space: O(1)
        """
        left, right = 0, len(s) - 1

        while left <= right:
            if not s[left].isalnum():
                left += 1
            elif not s[right].isalnum():
                right -= 1
            elif s[left].lower() == s[right].lower():
                left += 1
                right -= 1
            else:
                return False

        return True
