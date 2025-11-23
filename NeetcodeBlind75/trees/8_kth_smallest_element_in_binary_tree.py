from typing import Optional


# Definition of binary tree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
        Algorithm intuition:
            - we will write an iterative dfs algorithm
            - append curr node to stack and keep processing the left tree to maintain order
            - then do k -= 1 and check if k == 0, return node.val
        Time: O(n)
        Space: O(n)
        """
        curr = root
        stack = []

        while stack or curr:
            while curr:
                stack.append(curr)
                curr = curr.left

            curr = stack.pop()
            k -= 1
            if k == 0:
                return curr.val

            curr = curr.right
