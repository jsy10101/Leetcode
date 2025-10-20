from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Algorithm intuition:
            - we can use a sliding window approach
            - start iterating from the right side
            - increase left if prices[left] > prices[right]
            - we keep track of max profit in window
        Time: O(n)
        Space: O(1)
        """
        left = 0
        maxProfit = 0

        for right in range(len(prices)):
            while prices[left] > prices[right]:
                left += 1

            maxProfit = max(maxProfit, prices[right] - prices[left])

        return maxProfit
