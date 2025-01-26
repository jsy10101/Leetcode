// Bottom up solution
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // Step 2
        vector<int> dp(n + 1);

        // Step 3: Base cases are implicitly defined as they are 0

        // Step 4
        for (int i = 2; i <= n; i++) {
            // Step 5
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        
        // Step 6
        return dp[n];
    }
};