  void printAllNodes(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> queue;
        queue.push(root);

        cout << "[ ";
        while(!queue.empty()) {
            int nodesInCurrentLevel = queue.size();
			
			// Before the iteration starts the queue contains all the nodes at a given level
            for (int i = 0; i < nodesInCurrentLevel; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                cout << node->val << " ";

                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }
        }

        cout << "]";
    }
