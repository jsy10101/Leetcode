class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        Algorithm intuition:
            - iterate through each word in list of strings
                - for each word, store the counts
            - add the tuple key and val in dict(default)
        Time: O(m*n)
        Space: O(n) since the tuple we are storing has constant size
        """

        ans = defaultdict(list)
        for w in strs:
            counts = [0] * 26
            for ch in w:
                counts[ord(ch) - ord("a")] += 1
            ans[tuple(counts)].append(w)

        return list(ans.values())
