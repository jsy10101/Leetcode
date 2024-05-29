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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // First we check the edge case where we have 0 or 1 nodes only
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Let's imagine a list with four elements
        // 1 -> 2 -> 3 -> 4 -> null
        // after transformation, 2 -> 1 -> 3 -> 4 -> null
        // to break it down, we want the current head to point to head->next->next and head->next = head
        // remember the answer to return would be head->next, so save it at first in dummy

        ListNode* prevNode = nullptr;
        ListNode* dummy = head->next;

        while (head != nullptr && head->next != nullptr) {
            if (prevNode != nullptr) {
                // before: (2 -> 1 -> 3 -> 4 -> null)
                // prevNode: 1
                // head: 3
                // head->next: 4
                prevNode->next = head->next;
                // after: (2 -> 1 -> 4 <- 3)
            }
            ListNode* nextNode = head->next->next; 
            head->next->next = head; // 2 -> 1, 1 -> 2
            head->next = nextNode; // 2 -> 1, 1 -> 3
            prevNode = head;
            head = nextNode;
        }
        return dummy;
    }
};
