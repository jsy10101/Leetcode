class Solution:
    def minWindow(self, s: str, t: str) -> str:
        """
        Algorithm intuition:
            - Use sliding window with two hash maps (countT = target freq, window = current freq).
            - Track how many unique chars are "satisfied" (have == need).
            - Expand right pointer, update window count.
            - When all needs are met, shrink left pointer while valid to minimize window.
            - Keep track of smallest valid window found so far.
        Time: O(n + m)
        Space: O(n)
        """

        if t == "":
            return ""

        countT, window = {}, {}

        for c in t:
            countT[c] = 1 + countT.get(c, 0)

        res, resLen = [-1, -1], float("infinity")
        have, need = 0, len(countT)
        left = 0

        for right in range(len(s)):
            c = s[right]

            window[c] = 1 + window.get(c, 0)

            if c in countT and window[c] == countT[c]:
                have += 1

            while have == need:
                if (right - left + 1) < resLen:
                    resLen = right - left + 1
                    res = [left, right]

                window[s[left]] -= 1

                if s[left] in countT and window[s[left]] < countT[s[left]]:
                    have -= 1
                left += 1

        left, right = res

        return s[left : right + 1] if resLen != float("infinity") else ""
