from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        """
        Algorithm intuition:
            - given a word, we have to check every single cell in board and see if the path contains the next
                - character for the word we're searching
            - so essentially we have to run a dfs algorithm recursively using backtracking
        Time: O(m * n * 4^n) or O(m * 4^n)
        Space: O(n)
        """
        ROWS = len(board)
        COLS = len(board[0])
        visit = set()

        def dfs(r, c, i):
            if i == len(word):
                return True

            if (
                r < 0
                or c < 0
                or r == ROWS
                or c == COLS
                or (r, c) in visit
                or board[r][c] != word[i]
            ):
                return False

            visit.add((r, c))
            res = (
                dfs(r + 1, c, i + 1)
                or dfs(r, c + 1, i + 1)
                or dfs(r - 1, c, i + 1)
                or dfs(r, c - 1, i + 1)
            )
            visit.remove((r, c))
            return res

        for r in range(ROWS):
            for c in range(COLS):
                if dfs(r, c, 0):
                    return True

        return False
