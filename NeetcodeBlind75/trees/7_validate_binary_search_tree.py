from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        """
        Algorithm intuition:
            - define limits
            - if left, update upper limit
            - if right, update lower limit
            - if current node not in limits, return False
                - start with -inf, inf
            - recursively check for left and right subtrees
        Time: O(n)
        Space: O(n)
        """

        def dfs(node, leftLimit, rightLimit):
            if node is None:
                return True

            if not (leftLimit < node.val < rightLimit):
                return False

            isLeftBST = dfs(node.left, leftLimit, node.val)
            isRightBST = dfs(node.right, node.val, rightLimit)

            return isLeftBST and isRightBST

        return dfs(root, float("-inf"), float("inf"))
