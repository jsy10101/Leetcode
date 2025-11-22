import heapq
from typing import List

"""
Definition of Interval:
"""


class Interval:
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        """
        Algorithm intuition:
            - sort the intevals by start time
            - we need to keep track of meeting end times in order
                - we use min heap to track current meeting end times
            - as soon a current meeting gets over
                - check using start of current meeting
                - if that gets over -> pop meeting which finishes earliest from heap
            - in the end heap size contains the meetings which have not ended yet
            - hence we need that many min rooms to avoid conflict
        Time: O(n log n)
        Space: O(n)
        """
        intervals.sort(key=lambda interval: interval.start)
        min_heap = []

        for interval in intervals:
            if min_heap and interval.start >= min_heap[0]:
                heapq.heappop(min_heap)
            heapq.heappush(min_heap, interval.end)

        return len(min_heap)
