class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Algorithm intuition:
            - we can use a sliding window approach
            - we will maintain a hashset to check if the character at right index exists
                - if yes, then it's a duplicate and we increase our left window till s[left] is no longer s[right]
            - the charSet includes all the characters in the current window
        Time: O(n)
        Space: O(n)
        """
        seen = set()

        left = 0
        res = 0

        for right in range(len(s)):
            while s[right] in seen:
                seen.remove(s[left])
                left += 1

            seen.add(s[right])
            res = max(res, right - left + 1)

        return res
