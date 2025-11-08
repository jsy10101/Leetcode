from typing import List
from collections import deque


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        """
        Algorithm intuition:
            - do a dfs/bfs if curr cell is 1
        Time: O(m * n)
        Space: O(m * n)
        """
        ROWS, COLS = len(grid), len(grid[0])
        numIslands = 0
        dirs = ((-1, 0), (0, -1), (1, 0), (0, 1))

        def dfs(r, c):
            if r < 0 or c < 0 or r == ROWS or c == COLS or grid[r][c] == "0":
                return

            grid[r][c] = "0"

            dfs(r - 1, c)
            dfs(r, c - 1)
            dfs(r + 1, c)
            dfs(r, c + 1)

        def bfs(r, c):
            q = deque()

            q.append((r, c))

            while q:
                row, col = q.popleft()

                for dr, dc in dirs:
                    nr, nc = dr + row, dc + col

                    if (
                        nr < 0
                        or nc < 0
                        or nr == ROWS
                        or nc == COLS
                        or grid[nr][nc] == "0"
                    ):
                        continue
                    grid[nr][nc] = "0"
                    q.append((nr, nc))

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1":
                    # dfs(r, c)
                    bfs(r, c)
                    numIslands += 1

        return numIslands
