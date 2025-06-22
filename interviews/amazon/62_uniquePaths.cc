// Time: O(m * n);
// Space: O(m * n);
// Topics: 2-D Dynamic Programming
// Algo intuition:
//      - at a particular time we can only go down or right
//      - so for current r, c, we would be looking at gain from top row or left col
//      - if it is out of bounds 0th col or 0th row, then we will be out of bounds
//      - in this case we set the dp[i][j] = 1
//      - lastly, we return dp[m - 1][n - 1]
class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    int upIndexElem = dp[i - 1][j];
                    int leftIndexElem = dp[i][j - 1];
                    dp[i][j] += upIndexElem + leftIndexElem;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};