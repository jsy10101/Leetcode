/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Time: O(n)
// Space: O(1)
// Algo intuition:
//      make use of a pointer and iterate it n times, call it curr1
//      now start from the head again
//      note that curr1 is n positions ahead of headPointer
//      use a while loop to go till curr becomes nullptr
//      note that the head pointer will be at N - nth position
//      we can now just change the pointers next position
//      [1,2,3,4,5], n = 2
//      after n times, curr -> 3
//      newCurr -> 1
//      (curr -> 4, newCurr -> 2), (curr -> 5, newCurr -> 3), (curr -> nullptr, newCurr -> 4)
//      prev -> 3

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while (n > 0) {
            right = right->next;
            n--;
        }

        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;
    }
};