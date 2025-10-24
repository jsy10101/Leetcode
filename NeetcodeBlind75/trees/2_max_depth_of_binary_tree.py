from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        """
        Algorithm intuition:
            - use dfs to recurse through tree
            - cal depth of left and right subtrees
            - in the end, return 1 (height of current root) max(left, rigtht) subtrees
            - base case: root is None -> return 0 (no path)
        Time: O(n)
        Space: O(n)
        """
        if root == None:
            return 0

        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
