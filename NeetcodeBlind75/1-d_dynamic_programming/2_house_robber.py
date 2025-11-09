from typing import List


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
        Space: O(1)
        """
        n = len(nums)
        backTwo = nums[0]

        if n == 1:
            return backTwo

        backOne = max(nums[0], nums[1])

        for i in range(2, n):
            backOne, backTwo = max(nums[i] + backTwo, backOne), backOne

        return backOne
