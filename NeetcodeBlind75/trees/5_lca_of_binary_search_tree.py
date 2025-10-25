from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: Optional[TreeNode], p: Optional[TreeNode], q: Optional[TreeNode]
    ) -> Optional[TreeNode]:
        """
        Algorithm intuition:
            - if either of p, q, or root are Null then return None (basecase)
            - if max(p, q) is smaller than the val at root, therefore being a bst, lca should be in left subtree
            - similarly, if min(p, q) is greater than val at root -> lca should be in right (do recursion)
        Time: O(h)
        Space: O(h)
        """
        if not p or not q or not root:
            return None

        if max(p.val, q.val) < root.val:
            return self.lowestCommonAncestor(root.left, p, q)

        if min(p.val, q.val) > root.val:
            return self.lowestCommonAncestor(root.right, p, q)

        return root
