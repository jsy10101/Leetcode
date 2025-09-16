# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        Algorithm intuition:
            - we can use fast and slow pointer technique
            - fast moves double the speed of slow pointer
            - in the end, if ever fast = slow, then we have already seen that node
                - if yes, we have a cyle
        Time: O(n)
        Space: O(1)
        """

        slow = fast = head

        while fast and fast.next:
            if fast == slow:
                return True
            slow = slow.next
            fast = fast.next.next

        return False
