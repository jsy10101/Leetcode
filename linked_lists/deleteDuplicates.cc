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

// Algo intuition:
//      use fast pointer technique
//      compare current and next positions

// Time: O(n)
// Space: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (slow && slow->next) {
            fast = slow->next;
            if (slow->val == fast->val) {
                slow->next = fast->next;
                fast = slow->next;
            } else {
                slow = slow->next;
            }
        }
        return head;
    }
};
