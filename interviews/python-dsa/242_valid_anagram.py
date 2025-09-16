class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        """
        Algorithm intuition:
            - check if s and t have the same size, if not return false
            - define a list with default values 0, with each index corresponding to letter 'a' through 'z'
            - go through s, and add the counts
            - then iterate through t, if any letter count is 0, then we can return false and not an anagram
            - if we reach the end of t, then it is an anagram and we can return true
        Time: O(n)
        Space: O(1)
        """

        if len(s) != len(t):
            return False

        counts = [0] * 26

        for c in s:
            counts[ord(c) - ord("a")] += 1

        for c in t:
            if counts[ord(c) - ord("a")] < 1:
                return False
            counts[ord(c) - ord("a")] -= 1

        return True
