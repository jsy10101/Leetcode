// Time: O(m * n)
// Space: O(m * n) - recursion stack
// Topics: graphs, dfs
// Algo intution:
//      - define directions, we can either go up, down, right or left
//      - when running dfs, if we encounter a 1, that means it's an island. flip it to 0 to mark it as visited
//      - base case for dfs, if out of bounds or we encounter 0, we can return
//      - once dfs is complete, we can increment the count of islands
class Solution {
   private:
    int m;
    int n;

    vector<vector<int>> dirs = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}};

    void dfs(vector<vector<char>>& grid, int r, int c) {
        // base case
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
            return;
        }

        // flip 1 to 0 to mark visited
        grid[r][c] = '0';

        for (int i = 0; i < 4; ++i) {
            int row = r + dirs[i][0];
            int col = c + dirs[i][1];
            dfs(grid, row, col);
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int numIslands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};