# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        """
        Algorithm intuition:
            - base case: if root is empty, return False
            - we can declare a helper function dfs in which we can pass in curr sum
                - if we have a leaf node, we check if curr node val + curr sum = target
                    - if yes, return true, no otherwise
                - if not a leaf node, we traverse the left and right subtree
            - in the end, we only need to check if one of the paths contains the sum
        Time: O(n)
        Space: O(n)
        """

        def dfs(root: Optional[TreeNode], curr_sum: int) -> bool:
            if root == None:
                return False

            if root.left == None and root.right == None:
                return root.val + curr_sum == targetSum

            curr_sum += root.val
            left = dfs(root.left, curr_sum)
            right = dfs(root.right, curr_sum)

            return left or right

        return dfs(root, 0)
