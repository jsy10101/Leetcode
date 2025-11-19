from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        """
        Algorithm intuition:
            - sort all the intervals by start point and then by end point
            - append intervals[0] to res
            - then iterate through each interal in sorted intervals
            - extract lastEnd from res
            - now check if current interval merges by checking start <= lastEnd
                - if yes, just modify the current res[-1][1] to max(end, lastEnd)
        Time: O(n * log n)
        Space: O(n)
        """
        intervals.sort(key=lambda interval: interval[0])
        res = [intervals[0]]

        for start, end in intervals[1:]:
            lastEnd = res[-1][1]

            if start <= lastEnd:
                res[-1][1] = max(end, lastEnd)
            else:
                res.append([start, end])

        return res
