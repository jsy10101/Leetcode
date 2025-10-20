from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        """
        Algorithm intuition
            - use a two pointer approach
            - we move the pointer that points to lower height since we want to maximize area
            - keep track of maxArea
        Time: O(n)
        Space: O(1)
        """
        left, right = 0, len(height) - 1

        maxArea = 0

        while left < right:
            area = min(height[right], height[left]) * (right - left)
            maxArea = max(area, maxArea)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return maxArea
