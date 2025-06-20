// Time: O(m * n)
// Space: O(m * n)
// Algo intuition:
//      - DFS + memoization
class Solution {
   private:
    int m;
    int n;

    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& cache) {
        if (cache[r][c] != 0) {
            return cache[r][c];
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < dirs.size(); ++i) {
            int row = r + dirs[i][0];
            int col = c + dirs[i][1];

            if (row >= 0 && row < m && col >= 0 && col < n &&
                matrix[row][col] > matrix[r][c]) {
                cache[r][c] = max(cache[r][c], dfs(matrix, row, col, cache));
            }
        }

        cout << "cache[" << r << "][" << c << "]: " << cache[r][c] + 1 << endl;
        return ++cache[r][c];
    }

   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }

        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> cache = vector<vector<int>>(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, i, j, cache));
            }
        }

        return ans;
    }
};
