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
//      use fast and slow pointers to reach middle of list, then reverse only second part of List

// Time: O(n)
// Space: O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // now slow is in middle of list
        ListNode* curr = slow;
        ListNode* prevNode = nullptr;

        // reverse second half of the list
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }

        // Now prevNode is the new head for the second half of the list
        // We can now simply add head->val and prevNode->val to store max
        int maxTwinSum = INT_MIN;
        while (prevNode != nullptr) {
            int twinSum = head->val + prevNode->val;
            if (twinSum > maxTwinSum) {
                maxTwinSum = twinSum;
            }
            head = head->next;
            prevNode = prevNode->next;
        }

        return maxTwinSum;
    }
};
