from typing import List
from collections import deque


class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        """
        Algorithm intuition:
            - do a mult-source bfs
            - bfs is cool here since we can maintain a local dist variable and for every breadth layer we can assign the distance
            - we also don't want to visit nodes again so we'll maintain a hash set
        Time: O(m * n)
        Space: O(m * n)
        """
        ROWS, COLS = len(rooms), len(rooms[0])
        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        visit = set()
        q = deque()

        for r in range(ROWS):
            for c in range(COLS):
                if rooms[r][c] == 0:
                    q.append([r, c])
                    visit.add((r, c))

        dist = 0
        while q:
            for _ in range(len(q)):
                r, c = q.popleft()
                rooms[r][c] = dist

                for dr, dc in directions:
                    nr, nc = r + dr, c + dc

                    if (
                        nr < 0
                        or nc < 0
                        or nr == ROWS
                        or nc == COLS
                        or rooms[nr][nc] == -1
                        or (nr, nc) in visit
                    ):
                        continue

                    q.append([nr, nc])
                    visit.add((nr, nc))
            dist += 1
