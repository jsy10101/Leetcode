# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        """
        Algorithm intuition:
            - use a dict to map old node to new node
            - run dfs on each node, if the node is already created, return node
            - append neighbours for copy
        Time: O(n), n = V + E
        Space: O(V)
        """
        oldToNew = {}

        def dfs(node) -> Optional["Node"]:
            if node in oldToNew:
                return oldToNew[node]

            copy = Node(node.val)
            oldToNew[node] = copy

            for nei in node.neighbors:
                copy.neighbors.append(dfs(nei))

            return copy

        return dfs(node) if node else None
