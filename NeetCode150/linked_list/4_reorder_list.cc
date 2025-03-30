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
//      0 -> n, 1 -> n - 1, 2 -> n - 2, 3 -> n - 3
//      0 -> n -> 1 -> n - 1 -> 2 -> n - 2 -> 3 -> n - 3 ...
//      if we use slow and fast pointers, then we can have the slow pointer point to the middle element and the fast pointer point to the last element. the slow pointer would give the middle element
//      then we can use this middle point to reverse the second list and then merge the two lists
//      In this case, the edge case is to start the fast pointer from head->next;
//      this is important as then we will always have the second list (slow pointer) larger than the first list
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head;
        ListNode* l2 = reverseList(slow);

        while (l1 != nullptr && l2 != nullptr) {
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;
            
            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};