USE_DFS = False

from typing import List, Tuple, Set, Deque
from collections import deque


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        """
        Algorithm intuition:
            - use dfs/bfs to iterate and find the islands starting with 1
            - maintain a local area variable to count the area of current island in dfs algo
            - compare with maxArea and area to store area
        Time: O(m * n)
        Space: O(m * n)
        """

        ROWS = len(grid)
        COLS = len(grid[0])
        directions: List[Tuple[int, int]] = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        maxArea = 0
        visited: Set[int] = set()

        def _dfs(r: int, c: int) -> int:
            # boundary condition
            if (
                r < 0
                or r >= ROWS
                or c < 0
                or c >= COLS
                or (r, c) in visited
                or grid[r][c] == 0
            ):
                return 0

            currArea = 1
            # mark current node as visited
            # grid[r][c] = 0
            visited.add((r, c))

            for dr, dc in directions:
                currArea += _dfs(r + dr, c + dc)

            return currArea

        def _bfs(r: int, c: int) -> int:
            q: Deque[Tuple[int, int]] = deque()
            q.append((r, c))
            visited.add((r, c))

            currArea = 1

            while q:
                r, c = q.popleft()

                for dr, dc in directions:
                    nr, nc = r + dr, c + dc

                    if (
                        nr < 0
                        or nc < 0
                        or nr >= ROWS
                        or nc >= COLS
                        or grid[nr][nc] == 0
                        or (nr, nc) in visited
                    ):
                        continue
                    visited.add((nr, nc))
                    q.append((nr, nc))
                    currArea += 1

            return currArea

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    area = _dfs(r, c) if USE_DFS else _bfs(r, c)
                    maxArea = max(maxArea, area)

        return maxArea
