/******** Iterative Solution ********/
// Time: O(n) since each node is visited once
// Space: O(n) worst case, O(log n) when tree is balanced
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, 1));
        int ans = 0;

        while (!stack.empty()) {
            auto [node, depth] = stack.top();
            stack.pop();

            // preOrder DFS (since we are processing result before visiting
            // children)
            ans = max(ans, depth);

            if (node->left != nullptr) {
                stack.push(pair(node->left, depth + 1));
            }
            if (node->right != nullptr) {
                stack.push(pair(node->right, depth + 1));
            }
        }

        return ans;
    }
};
