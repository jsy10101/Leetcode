// Time: O(n)
// Space: O(n)
// Topic: 1-D Dynamic Programming
// Algorithm intuition:
//      - to reach step i
//          - take a single step from i - 1 or
//          - take 2 steps from i - 2
//      - dp[i] = dp[i - 1] + dp[i - 2]
class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};