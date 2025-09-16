class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        Algorithm intuition:
            - we can compute a prefix product and a postfix product
        Time: O(n)
        Space: O(n)
        """
        n = len(nums)
        if n == 1:
            return nums

        prefix = [1] * n
        suffix = [1] * n
        result = [1] * n

        for i in range(1, n):
            prefix[i] = nums[i - 1] * prefix[i - 1]

        for i in range(n - 2, -1, -1):
            suffix[i] = nums[i + 1] * suffix[i + 1]

        for i in range(n):
            result[i] = prefix[i] * suffix[i]

        return result
