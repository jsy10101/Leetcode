from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        """
        Algorithm intuition:
            - we can run a binary search
            - note that we don't have a target here
            - we find mid and check if nums[mid] > nums[right]
                - if yes, our min would be in right section -> left = mid + 1
                - else, min can be middle as well -> right = mid
        Time: O(log n)
        Space: O(1)
        """
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (left + right) // 2

            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        return nums[left]
