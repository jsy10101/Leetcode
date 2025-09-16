class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Algorithm intuition:
            - we can start with an empty hash map
            - {key = nums[i], val = index}
            - for every element in array, we check whether the complement is present in hash map
                - if yes, we return the index
                - else we iterate till end of num
        Time: O(n)
        Space: O(n)
        """
        m = {}

        for i, num in enumerate(nums):
            comp = target - num
            if comp in m:
                return [m[comp], i]
            m[num] = i

        return [-1, -1]
