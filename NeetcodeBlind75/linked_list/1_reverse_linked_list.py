from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Algorithm intuition:
            - create a pointer that points to the next
            - set prev = None
            - curr->next = prev
            - prev = curr
            - curr = next
        Time: O(n)
        Space: O(1)
        """
        curr = head
        prev = None

        while curr:
            nextP = curr.next
            curr.next = prev
            prev = curr
            curr = nextP

        return prev
