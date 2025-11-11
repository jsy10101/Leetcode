class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Algorithm intuition:
            - two pointers
                - l, r
                - swap l and r posittions till l <= r
        Time: O(n)
        Space: O(1)
        """

        l, r = 0, len(s) - 1

        while l <= r:
            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1

        return s
