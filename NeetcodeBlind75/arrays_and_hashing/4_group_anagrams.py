from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        Algorithm intuition:
            - declare a default dict of list
            - store the tuple of (counts) as value (since this will be constant) no extra size
            - append to default dict if an anagram is found
        Time: O(m * n)
        Space: O(m) where m = number of words and n = length of longest word
        """

        anagramsMap = defaultdict(list)

        for word in strs:
            counts = [0] * 26

            for ch in word:
                counts[ord(ch) - ord("a")] += 1

            anagramsMap[tuple(counts)].append(word)

        return list(anagramsMap.values())
