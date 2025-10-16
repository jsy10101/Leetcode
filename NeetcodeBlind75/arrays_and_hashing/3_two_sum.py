from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Algorithm intuition:
            - since input is not sorted, we can use a hashmap
            - we store the number as key and index of that number
            - iterate through the list and if a complement is present in hashmap, we return indices
        Time: O(n)
        Space: O(n)
        """

        hash_map = {}

        for i in range(len(nums)):
            comp = target - nums[i]

            if comp in hash_map:
                return [hash_map[comp], i]

            hash_map[nums[i]] = i

        return [-1, -1]
