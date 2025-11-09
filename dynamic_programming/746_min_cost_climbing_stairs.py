from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        """
        Algorithm intuition:
            - we need to minimize the cost
            - base cases, if i = 0 or i = 1, dp(i) = 0 since we can start from either step 0 or step 1
            - for any state i, we want to take the min of dp(i - 1) + cost(i - 1), dp(i - 2) + cost(i - 2)
            - for bottom up solution, we create a dp array of size (n + 1) since we need to step out of stairs
            - base cases same, dp[0] = dp[1] = 0 (we can start from either)
            - dp[i] = as above
        Time: O(n)
        Space: O(1)
        """

        n = len(cost)
        # dp = [0] * (n + 1)
        # dp[0] = dp[1] = 0

        down1 = down2 = 0
        for i in range(2, n + 1):
            # dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
            down1, down2 = min(down1 + cost[i - 1], down2 + cost[i - 2]), down1

        # return dp[n]
        return down1
