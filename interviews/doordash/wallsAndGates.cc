// Time: O(m * n)
// Space: O(m * n)
// Algo intuition:
//      - Multi source BFS
//      - guarantees shortest path
//      - initially we'll put all the gates in queue
//      - then we'll process the queue
//      - mark the distance of neighbours and put the neighbours in queue
//      - handle out of bounds edge case
class Solution {
   public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // push the gate coordinates to queue
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}};

        while (!q.empty()) {
            auto [r, c] = q.front();

            for (int i = 0; i < dirs.size(); ++i) {
                int row = r + dirs[i][0];
                int col = c + dirs[i][1];

                // boundary condition or closest distance already marked
                if (row < 0 || row >= m || col < 0 || col >= n || rooms[row][col] != INT_MAX) {
                    continue;
                }

                rooms[row][col] = rooms[r][c] + 1;
                q.push({row, col});
            }

            q.pop();
        }
    }
};