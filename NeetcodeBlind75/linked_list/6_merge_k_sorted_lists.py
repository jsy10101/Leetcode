import heapq
from typing import Optional, List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class NodeWrapper:
    def __init__(self, node):
        self.node = node

    def __lt__(self, other):
        return self.node.val < other.node.val


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        Algorithm intuition:
            - use a min_heap to store k nodes and extract min_node
            - define a node wrapper since we need a less than operator for min comparison between two nodes
            - pushing to min_heap would be O(log k) at worse and same for pop
            - once k nodes have been pushed, we extract the min, use a dummy and curr pointer to assign next
                - if next of current node is not None, push it to min heap
                - still, at max we will always have k elements in heap
        Time: O(n * log k)
        Space: O(k)
        """
        min_heap = []

        for lst in lists:
            if lst:
                heapq.heappush(min_heap, NodeWrapper(lst))

        dummy = ListNode(-1)
        curr = dummy

        while min_heap:
            nodeWrapper = heapq.heappop(min_heap)
            curr.next = nodeWrapper.node
            curr = curr.next

            if nodeWrapper.node.next:
                heapq.heappush(min_heap, NodeWrapper(nodeWrapper.node.next))

        return dummy.next
