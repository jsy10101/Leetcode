class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        """
        Algorithm intuition:
            - check if size of s and t is different
                -> return False if different
            - if we only have english letters, we can declare a constant size array (len 26) and count
            - first we count for s
            - then subtract each ord of character occurenece in t
            - at any time if any character count is less than 0 we return False
            - we do one more iteration through s to check if any character count is greater than 0, and return False
            - if all conditions pass we return true
        Time: O(n) where n = max(len(s), len(t))
        Space: O(1)
        """

        if len(s) != len(t):
            return False

        counts = [0] * 26

        for ch in s:
            counts[ord(ch) - ord("a")] += 1

        for ch in t:
            counts[ord(ch) - ord("a")] -= 1

        for c in counts:
            if c != 0:
                return False

        return True
