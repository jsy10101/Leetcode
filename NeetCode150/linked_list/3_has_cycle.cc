/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time: O(n)
// Space: O(1)
// Algo intuition:
//      - we can use the concept of slow and fast pointers
//      - one pointer moves twice as fast as the slow pointer
//      - if at any point, slow == fast, we return true
//      - above is only possible if we have a cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};