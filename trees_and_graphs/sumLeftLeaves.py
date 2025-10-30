from collections import deque
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        """
        Algorithm intuition:
            - we can either run a bfs/dfs algo to add only the left leaf sum
            - to check if we are on a leaf, both left and right nodes should be NULL
            - let's start with calculating both leaves sum
            - modified logic, pass in a boolean to specify if isLeft
            - if isLeft and and a leaf -> contribute to sum
        Time: O(n)
        Space: O(n)
        """
        if not root:
            return 0

        q = deque()
        q.append((root, False))
        leftLeafSum = 0

        while q:
            node, isLeft = q.popleft()
            # left leaf node
            if isLeft and node.left is None and node.right is None:
                leftLeafSum += node.val
            if node.left:
                q.append((node.left, True))
            if node.right:
                q.append((node.right, False))

        return leftLeafSum
