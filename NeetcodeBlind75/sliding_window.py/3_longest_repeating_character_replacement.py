class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        """
        Algorithm intuition:
            - use a sliding window approach
            - calculate the counts of each character in window
            - window break condition -> window size - most frequent character in map > k
            - above means if the number of replacements in window exceeds k, we have to shrink our window from left
            - we also declare maxF which is the maxFrequeny of the entire counts.
            - we don't have to update that for our sliding window since we are using an overestimation and it won't hurt
        Time: O(n)
        Space: O(n)
        """

        ans = 0
        counts = {}
        maxF = 0

        left = 0
        for right in range(len(s)):
            counts[s[right]] = 1 + counts.get(s[right], 0)

            maxF = max(maxF, counts[s[right]])

            while (right - left + 1) - maxF > k:
                counts[s[left]] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans
