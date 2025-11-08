from typing import List


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        """
        Algorithm intuition:
            - make an adj map
            - run dfs on map and count how many times dfs is run
                - increase counter only if current node not in visit
        Time: O(V + E)
        Space: O(V + E)
        """
        adjMap = [[] for _ in range(n)]

        for n1, n2 in edges:
            adjMap[n1].append(n2)
            adjMap[n2].append(n1)

        visit = set()  # to avoid revisiting nodes again

        def dfs(node):
            if node in visit:
                return

            visit.add(node)
            for nei in adjMap[node]:
                dfs(nei)

        connectedComps = 0

        for node in range(n):
            if node not in visit:
                dfs(node)
                connectedComps += 1

        return connectedComps
