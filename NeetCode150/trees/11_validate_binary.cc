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
// Algo intuition:
//      we define left and right boundaries
//      when checking the left subtree, we update the right boundary to be the current node
//      when checking the right subtree, we update the left boundary to be the current node
class Solution {
private:
    bool dfs(TreeNode *node, long leftBoundary, long rightBoundary) {
        if (node == nullptr) {
            return true;
        }

        if ( !(leftBoundary < node->val && node->val < rightBoundary) ) {
            return false;
        }

        bool left = dfs(node->left, leftBoundary, node->val);
        bool right = dfs(node->right, node->val, rightBoundary);

        return left && right;
    }

public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};