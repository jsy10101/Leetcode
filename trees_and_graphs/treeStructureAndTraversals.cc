struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void preOrderDFS(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->val << " ";
    preOrderDFS(node->left);
    preOrderDFS(node->right);
    return;
}

void inOrderDFS(Node* node) {
    if (node == nullptr) {
        return;
    }
    inOrderDFS(node->left);
    cout << node->val << " ";
    inOrderDFS(node->right);
    return;
}

void postOrderDFS(Node* node) {
    if (node == nullptr) {
        return;
    }
    postOrderDFS(node->left);
    postOrderDFS(node->right);
    cout << node-> val << " ";
    return;
}

int main() {
    /*
    The following code builds a tree that looks like:
        0
      /   \
     1     2
    */
    
    Node* root = new Node(0);
    Node* one = new Node(1);
    Node* two = new Node(2);
    
    root->left = one;
    root->right = two;
    
    cout << root->left->val << endl; // Prints 1
    cout << root->right->val << endl; // Prints 2
    
    cout << "\n--------------------" << endl;
    cout << "pre Order DFS: " << endl; 
    preOrderDFS(root);
    cout << "\n--------------------" << endl;
    
    cout << "in Order DFS: " << endl; 
    inOrderDFS(root);
    cout << "\n--------------------" << endl;
    
    cout << "post Order DFS: " << endl; 
    postOrderDFS(root);
    cout << "\n--------------------" << endl;
    
}

/************ OUTPUT ****************/
// 1
// 2

// --------------------
// pre Order DFS: 
// 0 1 2 
// --------------------
// in Order DFS: 
// 1 0 2 
// --------------------
// post Order DFS: 
// 1 2 0 
// --------------------
