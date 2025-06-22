// Time: O(m * n)
// Space: O(1)
// Topics: 2-D Dynamic Programming
// Algo intuition:
//      - at a particular time, we can only go down or right
//      - we have to take care of obstacles
//      - we can treat the grid as a dp and tabulate accordingly
//      - general contribution for current cell -> upper cell + left cell
//      - now base cases, fill in the first row and first cols
//      - if there is an obstacle, set it to 0
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // if obstacle at first position return 0
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // if above is not true, there is one way to reach cell at 0, 0
        obstacleGrid[0][0] = 1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // Now let's fill in the first col
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) {
                obstacleGrid[i][0] = 1;
            } else {
                obstacleGrid[i][0] = 0;
            }
        }

        // Similarly let's fill in the first row
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) {
                obstacleGrid[0][i] = 1;
            } else {
                obstacleGrid[0][i] = 0;
            }
        }

        // General case, starting at cell (1,1)
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    int up = obstacleGrid[i - 1][j];
                    int left = obstacleGrid[i][j - 1];
                    obstacleGrid[i][j] = up + left;
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }

        return obstacleGrid[m - 1][n - 1];
    }
};