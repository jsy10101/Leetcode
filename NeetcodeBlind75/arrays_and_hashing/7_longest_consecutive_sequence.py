from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """
        Algorithm intuition:
            - we can use a hash set to store distinct elements
            - to check if an element in sequence does not exist, we check if (num - 1) not in numSet
                - if yes we reset length = 1 (identify as first element in sequence)
            - keep track of max length
        Time: O(n)
        Space: O(n)
        """
        numSet = set(nums)
        longest = 0

        for num in numSet:
            if (num - 1) not in numSet:
                length = 1

                while (num + length) in numSet:
                    length += 1
                longest = max(longest, length)

        return longest
