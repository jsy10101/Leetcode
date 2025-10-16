from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        """
        Algorithm intuition:
            - we can use a set
            - iteratively go through the all the elements
            - if any value is already in the set, we have found a duplicate and return true, else false
        Time: O(n)
        Space: O(n)
        """

        seen = set()

        for num in nums:
            if num in seen:
                return True
            seen.add(num)

        return False
