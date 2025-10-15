from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        """
        Algorithm intuition:
            - Topological sort with dfs
            - maintain two hashsets (visit and cycle)
            - if cycle is detected while running dfs, return false, else continue
            - once dfs is done, remove from cycle set and add to visit set to avoid revisiting
        Time: O(V + E)
        Space: O(V + E)
        """

        preMap = {i: [] for i in range(numCourses)}

        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        visit, cycle = set(), set()
        output = []

        def dfs(crs) -> bool:
            if crs in cycle:
                return False
            if crs in visit:
                return True

            cycle.add(crs)

            for pre in preMap[crs]:
                if dfs(pre) == False:
                    return False

            cycle.remove(crs)
            visit.add(crs)
            output.append(crs)

            return True

        for c in range(numCourses):
            if dfs(c) == False:
                return []

        return output
