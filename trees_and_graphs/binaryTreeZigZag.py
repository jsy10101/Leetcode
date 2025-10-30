from collections import deque
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        Algorithm intuition:
            - since we are concerned with levels we can use a bfs algorithm
            - we can also use a boolean to specify the print direction, True (for left->right)
            - base case: root is None -> return []
            - we can make use of a deque (double ended queue in python), if reverse -> pop else popleft
                - that means, if reversed, we can pop from back and else pop from front
            - important: when reversed, we need to append to left instead of normal append
        Time: O(n)
        Space: O(n)
        """
        if root is None:
            return []

        res = []
        isLeftToRight = True

        q = deque()
        q.append(root)

        while q:
            levelElems = []

            for _ in range(len(q)):
                if isLeftToRight:
                    node = q.popleft()
                    levelElems.append(node.val)

                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
                else:
                    node = q.pop()
                    levelElems.append(node.val)

                    if node.right:
                        q.appendleft(node.right)
                    if node.left:
                        q.appendleft(node.left)

            res.append(levelElems)
            isLeftToRight = not isLeftToRight

        return res
