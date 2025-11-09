from typing import List
from functools import cache


class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        Algorithm intuition:
            - base cases:
                - if n <= 1, return nums[0]
                - if n == 2, return max(num[0], nums[1])
            - for the third house, we could have either robbed 1 + house 3 or just 2, we take the max
            - this is the recursive case we keep in mind
            - we start with last house, and rob previous house or current house + last to last house whatever returns max
        Time: O(n)
        Space: O(n)
        """

        @cache
        def dp(i):
            if i == 0:
                return nums[0]
            if i == 1:
                return max(nums[0], nums[1])

            return max(nums[i] + dp(i - 2), dp(i - 1))

        return dp(len(nums) - 1)
