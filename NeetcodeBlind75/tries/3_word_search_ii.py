from typing import List


class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False

    def addWord(self, word: str):
        curr = self

        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]

        curr.endOfWord = True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        """
        Algorithm intuition:
            - we can make use of prefix tree or Tries to optimize our solution
            - we initially create a prefix tree data structure to store all the possible words
            - then we can do backtracking on each possible character in board to check if the word exists in trie
            - because of trie, we add a base case as well to backtracking where we can terminate early if current character is not in the current trie level and exit early
        Time: O(m * n * 4 * 3^(t - 1) + s)
        Space: O(s)
        """
        root = TrieNode()

        for word in words:
            root.addWord(word)

        ROWS, COLS = len(board), len(board[0])
        res, visit = set(), set()
        dirs = ((-1, 0), (0, -1), (1, 0), (0, 1))

        def dfs(r, c, node, word):
            if (
                r < 0
                or c < 0
                or r == ROWS
                or c == COLS
                or (r, c) in visit
                or board[r][c] not in node.children
            ):
                return

            visit.add((r, c))

            node = node.children[board[r][c]]
            word += board[r][c]
            if node.endOfWord:
                res.add(word)

            for dr, dc in dirs:
                dfs(r + dr, c + dc, node, word)

            visit.remove((r, c))

        for r in range(ROWS):
            for c in range(COLS):
                dfs(r, c, root, "")

        return list(res)
