// Algo intuition: fast moves twice as fast as slow pointer.
//  Hence if at any time fast == slow, this means we have a cycle

// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};