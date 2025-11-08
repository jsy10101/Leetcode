from typing import List


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        """
        Algorithm intuition:
            - make an adjacency map that stores nodes and it's neighbors
                - since this is an undirected graph, we need to append to both node and it's neighbors in adjMap
            - run a dfs algorithm with a visit set
            - if we detect a cycle, return False
            - only return true if there was not a cycle and number of nodes in visit set = n (connected component check)
        Time: O(V + E)
        Space: O(V + E)
        """
        if len(edges) > (n - 1):
            return False

        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visit = set()

        def dfs(node, pre):
            if node in visit:
                return False

            visit.add(node)
            for nei in adj[node]:
                if nei == pre:
                    continue
                if not dfs(nei, node):
                    return False
            return True

        return dfs(0, -1) and len(visit) == n
