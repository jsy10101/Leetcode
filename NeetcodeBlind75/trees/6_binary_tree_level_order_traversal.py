from collections import deque
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        Algorithm intuition:
            - do a simple bfs algo and for each level add the val the level
            - append current level to res -> res stores a list of all level vals
        Time: O(n)
        Space: O(n)
        """
        res = []

        def bfs(node: Optional[TreeNode]) -> None:
            q = deque()

            if not root:
                return

            q.append(root)

            while q:
                qLevel = []
                for _ in range(len(q)):
                    node = q.popleft()
                    qLevel.append(node.val)
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
                res.append(qLevel)

        def dfs(node: Optional[TreeNode], depth: int) -> None:
            if node == None:
                return

            if len(res) == depth:
                res.append([])

            res[depth].append(node.val)
            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)

        # bfs(root)
        dfs(root, 0)
        return res
