from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        """
        Algorithm intuition:
            - we can use a greedy approach using two pointers
            - iterate n steps forward with first pointer
            - initialize a dummy pointer with next as head
            - when first pointer reaches n steps, left would be n + 1 steps behind
            - iterate till first pointer is null
                - at this point, left.next would point to the n-th element from the end
            - to remove, change left.next = left.next.next
        Time: O(n)
        Space: O(1)
        """

        dummy = ListNode(-1, head)
        right = head

        left = dummy

        for _ in range(n):
            right = right.next

        while right:
            right = right.next
            left = left.next

        left.next = left.next.next

        return dummy.next
