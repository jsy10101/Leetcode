from typing import List


class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        """
        Algorithm intuition:
            - if newEnd is less than start of current interval
                - append new intervals and then append rest of the intervals
            - if newStart is greater than end of current interval, insert current interval
            - else we have a merging condition
                - new interval would be min(start, newStart) and max(end, newEnd)
            - edge case: if we don't return and the new interval should go in back, append it in the end
        Time: O(n)
        Space: O(1) or O(n) for output
        """
        newStart, newEnd = newInterval
        res = []

        for i in range(len(intervals)):
            if newEnd < intervals[i][0]:
                res.append([newStart, newEnd])
                return res + intervals[i:]
            elif newStart > intervals[i][1]:
                res.append(intervals[i])
            else:
                newStart, newEnd = min(intervals[i][0], newStart), max(
                    intervals[i][1], newEnd
                )

        res.append([newStart, newEnd])

        return res
