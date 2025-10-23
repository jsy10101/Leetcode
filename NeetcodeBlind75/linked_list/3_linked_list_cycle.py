from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        Algorithm intuition:
            - define two pointers
            - fast and slow
            - fast moves twice as slow
            - if it any time fast = slow after setting it to next, then we have a cycle
        Time: O(n)
        Space: O(1)
        """

        slow = fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True

        return False
