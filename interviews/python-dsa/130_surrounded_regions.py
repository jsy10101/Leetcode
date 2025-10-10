from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        """
        Algorithm intuition:
            - we can use dfs
            - 1. reverse thinking: capture everything but the unsurrounded region and mark it as T
            - 2. capture surrounded regions (mark O as X)
            - 3. uncapture the unsurrounded region (mark T -> O)
        Time: O(m * n)
        Space: O(m * n)
        """
        ROWS, COLS = len(board), len(board[0])
        dirs = [(-1, 0), (0, -1), (1, 0), (0, 1)]

        def capture(row: int, col: int) -> None:
            if (
                row < 0
                or col < 0
                or row == ROWS
                or col == COLS
                or board[row][col] != "O"
            ):
                return

            board[row][col] = "T"

            for dr, dc in dirs:
                capture(row + dr, col + dc)

        for r in range(ROWS):
            capture(r, 0)
            capture(r, COLS - 1)

        for c in range(COLS):
            capture(0, c)
            capture(ROWS - 1, c)

        for r in range(ROWS):
            for c in range(COLS):
                # capture surrounded region
                if board[r][c] == "O":
                    board[r][c] = "X"
                # uncapture unsurrounded region
                elif board[r][c] == "T":
                    board[r][c] = "O"
