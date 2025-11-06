from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        Algorithm intuition:
            - we can do a binary search
            - we can define left and right bounds (left = 0, right = nums.length - 1) -> 0 indexed
            - we check if the value at mid = left + right / 2 is our target, we return
            - if val at middle is greater than target -> shrink right window -> right = mid -1
            - else shrink left window
            - if we exit out of the loop, return -1 (does not exist)
        Time:
        Space:
        """
        left, right = 0, len(nums) - 1

        print((1 + 2) // 2)
        print((0 + 2) // 2)
        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid
            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1

        return -1
