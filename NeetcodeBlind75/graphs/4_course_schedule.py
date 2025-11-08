from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """
        Algorithm intuition:
            - basically given an adjacency list, we can build out a preReq map that would map the current course and it's prerequistes
            - this would help us in running a dfs on the preReq and check if they can be completed
            - to check if a course is completed, it should have no preReq or it's preReq map should be empty
            - the second thing that we need to make sure is detecting a cycle.
                - if there is a cycle, we return false
        Time: O(n)
        Space: O(n)
        """

        preMap = {i: [] for i in range(numCourses)}
        visit = set()

        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        def dfs(crs):
            # cycle detection
            if crs in visit:
                return False

            if preMap[crs] == []:
                return True

            visit.add(crs)

            for pre in preMap[crs]:
                if not dfs(pre):
                    return False

            preMap[crs] = []
            visit.remove(crs)

            return True

        for crs in range(numCourses):
            if not dfs(crs):
                return False

        return True
