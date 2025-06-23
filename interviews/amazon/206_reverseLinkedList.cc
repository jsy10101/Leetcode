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
// Topic: Linked list
// Algo intuition:
// 1 -> 2 -> 3 -> 4 -> 5
// 5 -> 4 -> 3 -> 2 -> 1
// let's say curr = head, prev = nullptr
//  we want to store next
//  then point curr to next

//  prev = nullptr, *curr = 1, next = *curr->next = 2
//  curr->next = prev, prev = curr,
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        if (curr == nullptr || curr->next == nullptr) return head;

        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        curr->next = prev;

        return curr;
    }
};