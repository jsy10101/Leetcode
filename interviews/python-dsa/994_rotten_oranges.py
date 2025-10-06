from collections import deque
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        """
        Algorithm intuition:
            - we can use a multi-source bfs solution for this.
            - first we mark all the rotten oranges
            - then we run bfs and keep track of visited nodes
            - once all the oranges at a level have been marked rotten, we append neighbours
        Time: O(m * n)
        Space: O(m * n)
        """
        ROWS, COLS = len(grid), len(grid[0])

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        q = deque()
        time = 0
        fresh = 0

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    fresh += 1
                elif grid[r][c] == 2:
                    q.append((r, c))

        while fresh > 0 and q:
            for _ in range(len(q)):
                r, c = q.popleft()
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc

                    if nr in range(ROWS) and nc in range(COLS) and grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        q.append((nr, nc))
                        fresh -= 1
            time += 1

        return time if fresh == 0 else -1
