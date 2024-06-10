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
    int target;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        return dfs(root, 0);
    }

    bool dfs(TreeNode* node, int curr) {
        // base case, root = null, hence return false
        if (node == nullptr) {
            return false;
        }
        
        // leaf node
        if (node->left == nullptr && node->right == nullptr) {
            return (curr + node->val) == target;
        }

        curr += node->val;
        bool left = dfs(node->left, curr);
        bool right = dfs(node->right, curr);

        // if either path returns true (ans == target), we return truth value accordingly
        // in other words, either path can have the target sum
        return left || right;
    }
};
