/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


// Time: O(n)
// Space: O(n)
// Algo intuition:
//      Create a map to store the nodes in the first pass (don't assign next yet)
//      map<oldNode, newNode>
//      in the second pass, we have have the elements in map
//      assign next and random

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[nullptr] = nullptr;

        Node* curr = head;

        while (curr != nullptr) {
            oldToCopy[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr != nullptr) {
            oldToCopy[curr]->next = oldToCopy[curr->next];
            oldToCopy[curr]->random = oldToCopy[curr->random];
            curr = curr->next;
        }

        return oldToCopy[head];
    }
};