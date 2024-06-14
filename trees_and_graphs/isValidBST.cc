/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    bool dfs(TreeNode* node, long min, long max) {
        if (node == nullptr) {
            return true;
        }
        if (min >= node->val || node->val >= max) {
            return false;
        }
        bool left = dfs(node->left, min, node->val);
        bool right = dfs(node->right, node->val, max);
        return left && right;
    }
};