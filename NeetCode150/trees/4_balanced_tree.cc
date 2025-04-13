/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// Time: O(n)
// Space: O(log n) best -> balanced tree, O(n) worst
// Algo intuition:
//      we're gonna define another function dfs which returns a pair(balanced,
//      height) we use this helper function to determine that the tree is
//      balanced at every node
class Solution {
    pair<bool, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {true, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int balanced = ((left.first && right.first) &&
                        (abs(left.second - right.second) <= 1));

        return {balanced, 1 + max(left.second, right.second)};
    }

public:
    bool isBalanced(TreeNode* root) { return dfs(root).first; }
};