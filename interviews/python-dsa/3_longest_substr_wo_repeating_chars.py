class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Algorithm intuition:
            - we can use a sliding window approach and a set
            - we can start by incrementing right pointer and adding current character to set
            - each time, we check if window is violated, (current character is in set)
                - if yes, we move the left pointer and remove left pointer element from set
        Time: O(n)
        Space: O(m) where m = unique characters in s
        """
        seen = set()

        left = ans = 0

        for right in range(len(s)):
            while s[right] in seen:
                seen.remove(s[left])
                left += 1

            seen.add(s[right])
            ans = max(ans, right - left + 1)

        return ans
