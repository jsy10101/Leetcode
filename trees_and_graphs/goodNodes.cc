// Time: O(n)
// Space: O(n)
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
    
    int dfs(TreeNode* node, int maxSoFar) {
        if (node == nullptr) {
            return 0;
        }
        
        int left = dfs(node->left, max(maxSoFar, node->val));
        int right = dfs(node->right, max(maxSoFar, node->val));
        int ans = left + right;
        if (node->val >= maxSoFar) {
            ans++;
        }
        
        return ans;
    }
};
