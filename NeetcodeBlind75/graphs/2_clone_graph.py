from typing import Optional


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        """
        Algorithm intuition:
            - we need to make a deep copy of the graph
            - we can use a hash map to store old to new node relation
            - for each node we create a copy
            - next step is to connect the neighbours
                - for this we take our current node and run a dfs, creating new copy of neighbors and appending the neighbor to current node
                - if we have already created a node copy, we just return it using our oldToNew hash map
        Time: O(V + E)
        Space: O(V)
        """
        oldToNew = {}

        def dfs(node):
            if node in oldToNew:
                return oldToNew[node]

            copy = Node(node.val)
            oldToNew[node] = copy

            for nei in node.neighbors:
                copy.neighbors.append(dfs(nei))

            return copy

        return dfs(node) if node else None
