from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        """
        Algorithm intuition:
            - sort intervals
            - find prev end (intially intervals[0][1])
            - start intervals from [1] (skip first)
                - now if start >= prevEnd, (non-overlapping)
                - else overlapping, increase 1 for overlapping and change prevEnd to min of end and prevEnd
        Time: O(n log n)
        Space: O(n)
        """
        intervals.sort(key=lambda interval: interval[0])
        res = 0
        prevEnd = intervals[0][1]

        for start, end in intervals[1:]:
            if start >= prevEnd:
                prevEnd = end
            else:
                res += 1
                prevEnd = min(end, prevEnd)

        return res
