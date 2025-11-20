from typing import List


class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        """
        Algorithm intuition:
            - basic logic: check for overlapping intervals
            - sort the intervals by start time
            - check if lastEnd is greater than current start
                - if yes, return False as then the person can't attend all meetings
                - else set lastEnd = end
            - if we make it through the loop, return True as then we have no overlapping meetings
        Time: O(n log n)
        Space: O(1)
        """
        if len(intervals) <= 1:
            return True

        intervals.sort(key=lambda interval: interval[0])
        lastEnd = intervals[0][1]

        for start, end in intervals[1:]:
            if lastEnd > start:
                return False
            else:
                lastEnd = end

        return True
