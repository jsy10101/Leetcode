from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        Algorithm intuition:
            - create a pre and post product (exclude element itself)
        Time: O(n)
        Space: O(n)
        """

        n = len(nums)
        res = [1] * n
        preProduct = [1] * n
        postProduct = [1] * n

        for i in range(1, n):
            preProduct[i] = nums[i - 1] * preProduct[i - 1]

        for i in range(n - 2, -1, -1):
            postProduct[i] = nums[i + 1] * postProduct[i + 1]

        for i in range(n):
            res[i] = preProduct[i] * postProduct[i]

        return res
