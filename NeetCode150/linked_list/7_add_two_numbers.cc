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

// Time: O(n + m)
// Space: O(1) since we are not counting the space of the returned answer
// Algo intuition:
//      compare the two nodes
//      add intermediate result.
//          - if greater than 10, store in carryover
//          - next time add intermediate result + carryover and then set carryover to 0
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carryOver = 0;

        while (l1 != nullptr || l2 != nullptr || carryOver != 0) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int val = val1 + val2 + carryOver;
            carryOver = val / 10;
            val = val % 10;

            curr->next = new ListNode(val);

            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};