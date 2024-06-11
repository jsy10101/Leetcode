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
    int dfs(TreeNode* node, int maxSoFar, int minSoFar) {
        if (node == nullptr) {
            return maxSoFar - minSoFar;
        }
        
        int left = dfs(node->left, max(maxSoFar, abs(node->val)), min(minSoFar, abs(node->val)));
        int right = dfs(node->right, max(maxSoFar, abs(node->val)), min(minSoFar, abs(node->val)));
        
        return max(left, right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
