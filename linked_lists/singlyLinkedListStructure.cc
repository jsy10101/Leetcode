struct LinkedListNode {
    int data;
    LinkedListNode* next;
    LinkedListNode(int val): data{val}, next{nullptr} {}
};

// Time: O(1)
// should know the prevNode and the nodeToAdd
void addNode(LinkedListNode* prevNode, LinkedListNode* nodeToAdd) {
    nodeToAdd->next = prevNode->next;
    prevNode->next = nodeToAdd;
}

// Time: O(1)
// should know the prevNode
void deleteNode(LinkedListNode* prevNode) {
    prevNode->next = prevNode->next->next;
}

// Time: O(n)
// Traverse till length of linked list
void printList(LinkedListNode* head) {
    while(head) {
        cout << head->data;
        if (head->next) {
            cout << "->";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    LinkedListNode* node1 = new LinkedListNode(1);
    LinkedListNode* node2 = new LinkedListNode(2);
    LinkedListNode* node3 = new LinkedListNode(3);
    LinkedListNode* node4 = new LinkedListNode(4);
    
    node1->next = node2;
    node2->next = node3;
    
    printList(node1); 
    
    addNode(node2, node4);
    printList(node1);
    
    deleteNode(node2);
    printList(node1);
        
}
