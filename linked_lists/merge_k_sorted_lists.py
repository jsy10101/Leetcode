from typing import Optional, List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        Algorithm intuition:
            - brute force
            - store all node vals in a list
            - sort the list containing node vals
            - create a dummy and curr pointer
            - for each node val -> create a new node
        Time: O(n * log n)
        Space: O(n)
        """
        res = []

        for llist in lists:
            while llist:
                res.append(llist.val)
                llist = llist.next

        res.sort()

        dummy = ListNode(-1)
        curr = dummy

        for nodeVal in res:
            node = ListNode(nodeVal)
            curr.next = node
            curr = curr.next

        return dummy.next
