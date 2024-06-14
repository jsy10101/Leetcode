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
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int ans = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()) {
            ans = 0;
            int nodesInCurrentLevel = queue.size();
    
            
            for (int i = 0; i < nodesInCurrentLevel; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                ans += node->val;
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
        }
        
        return ans;
    }
};
