from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        """
        Algorithm intuition:
            - both p and q nodes should have same vals
            - both left and right children should be same
            - if p is None and q is not None or p is not None and q is None then return false
        Time: O(n)
        Space: O(n)
        """
        if not p and not q:
            return True

        if (p and not q) or (not p and q):
            return False

        if p.val != q.val:
            return False

        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
