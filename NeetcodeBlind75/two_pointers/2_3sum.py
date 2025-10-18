from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        """
        Algorithm intuition:
            - sort the nums first
            - skip duplicates (if current = prev continue)
            - basically for each num, we are iterating, if curr num > 0 then three sum can't be 0, hence break
            - do a two pointer approach to find if threeSum = 0 exists and push
        Time: O(n^2)
        Space: O(1)
        """

        res = []
        nums.sort()

        for i, a in enumerate(nums):
            if a > 0:
                break

            if i > 0 and a == nums[i - 1]:
                continue

            left, right = i + 1, len(nums) - 1

            while left < right:
                threeSum = a + nums[left] + nums[right]

                if threeSum < 0:
                    left += 1
                elif threeSum > 0:
                    right -= 1
                else:
                    res.append([a, nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while nums[left] == nums[left - 1] and left <= right:
                        left += 1

        return res
