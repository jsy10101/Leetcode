from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        """
        Algorithm intuition:
            - the root will always be at the first index of preorder
            - create a new root
            - find index of preorder[0] and call it mid
            - mid is used a partition point for preorder and inorder
            - for left tree
                - preoder[1: mid + 1] skip root and take mid elements
                - order[: mid] all elements before root
            - for right tree
                - preorder[mid + 1: ] skip root and left sub-tree elements
                - inorder[mid + 1: ] all elements after root
        Time: O(n^2)
        Space: O(n)
        """
        if not preorder or not inorder:
            return None

        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1 : mid + 1], inorder[:mid])
        root.right = self.buildTree(preorder[mid + 1 :], inorder[mid + 1 :])

        return root
