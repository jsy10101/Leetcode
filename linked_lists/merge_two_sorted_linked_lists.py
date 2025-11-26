from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        """
        Algorithm intuition:
            - create a dummy node and currnode that both point to head
            - dummy.next would be later used to return the head of the sorted list
            - compare the two list val nodes and assign curr.next to list pointer
        Time: O(n)
        Space: O(1)
        """
        dummy = ListNode(-1)
        curr = dummy

        while list1 and list2:
            if list1.val < list2.val:
                node = ListNode(list1.val)
                list1 = list1.next
            else:
                node = ListNode(list2.val)
                list2 = list2.next
            curr.next = node
            curr = curr.next

        if list2:
            curr.next = list2
        if list1:
            curr.next = list1

        return dummy.next


# [4] [4]
# dummy = [-1, 1, 1, 2, 3]
# curr = [3]
