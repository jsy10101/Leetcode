USE_DFS = False

from typing import List
from collections import deque


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        """
        Algorithm intuition:
            - do a dfs until base case is reached
            - the number of times dfs is executed will give us the island count
            - each time we visit a cell, if water, we mark it as 0 so that we don't revisit it
            - same for bfs
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

        def bfs(r: int, c: int) -> None:
            queue = deque()
            queue.append((r, c))
            # mark current node as visited
            grid[r][c] = "0"

            while queue:
                row, col = queue.popleft()
                for dr, dc in directions:
                    # pop the last element from queue and process it
                    nr, nc = row + dr, col + dc

                    if (
                        nr < 0
                        or nc < 0
                        or nr >= ROWS
                        or nc >= COLS
                        or grid[nr][nc] == "0"
                    ):
                        # skip adding current to queue
                        continue
                    queue.append((nr, nc))
                    # mark cell at nr, nc as visited
                    grid[nr][nc] = "0"

        ans = 0
        ROWS = len(grid)
        COLS = len(grid[0])

        for row in range(ROWS):
            for col in range(COLS):
                if grid[row][col] == "1":
                    if USE_DFS:
                        dfs(row, col)
                    else:
                        bfs(row, col)
                    ans += 1

        return ans
