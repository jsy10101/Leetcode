from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        Algorithm intuition:
            - maximize money robbed -> dp
            - state variable -> i (money robbed)
        Time: O(n)
        Space: O(1)
        """
        n = len(nums)

        if n == 1:
            return nums[0]

        backTwo = nums[0]
        backOne = max(nums[0], nums[1])

        for i in range(2, n):
            backOne, backTwo = max(backOne, backTwo + nums[i]), backOne

        return backOne
