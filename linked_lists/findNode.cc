// Algo intuition:
//	since we move the faster `k` ahead this is the same as saying that the
//		slow pointer is `k` behind.
//		Hence to find 2nd last node, we move the fast pointer 2 ahead
//		and the position at which slow pointer ends would be 2 behind
//		which means we will retrieve the second last element.

// Time: O(n)
// Space: O(1)
ListNode* findNode(ListNode* head, int k) {
	ListNode* fast = head;
	ListNode* slow = head;

	for (int i = 0; i < k; ++i) {
		fast = fast->next;
	}

	while (fast != nullptr) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}
