from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        """
        Algorithm intuition:
            - do a dfs until base case is reached
            - the number of times dfs is executed will give us the island count
            - each time we visit a cell, if water, we mark it as 0 so that we don't revisit it
        Time: O(m * n)
        Space: O(m * n)
        """

        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

        def dfs(r: int, c: int) -> None:
            if r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] == "0":
                return

            grid[r][c] = "0"

            for dr, dc in directions:
                dfs(r + dr, c + dc)

        ans = 0
        ROWS = len(grid)
        COLS = len(grid[0])

        for row in range(ROWS):
            for col in range(COLS):
                if grid[row][col] == "1":
                    dfs(row, col)
                    ans += 1

        return ans
