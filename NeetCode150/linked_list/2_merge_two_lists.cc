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

// Time: O(n + m), where n = list1.size() and m = list2.size()
// Space: O(1), just one pointer node is declared on heap
// Algo intuition:
//      - we declare a dummy ListNode pointer on heap (delete it later manually or use stack allocation)
//      - declaring on heap uses constant extra space
//      - then check the pointers at list1 and list2
//      - add the value to temp->next and update next pointers of list1 and list2
//      - remember to update temp = temp->next;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Manually delete the allocated heap memory node to avoid memory leak
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};