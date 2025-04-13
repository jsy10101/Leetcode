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
// Space: O(n) worst and O(log n) best for balanaced tree
// Algo intuition:
//      we will declare a global variable res which will hold the max diameter
//      we will also declare another helper function called dfs which will help us calculate the max diameter
class Solution {
private:
    // returns height
    int dfs(TreeNode* node, int &res) {
        if (node == nullptr) {
            return 0;
        }

        int left = dfs(node->left, res);
        int right = dfs(node->right, res);

        // this is the diamter
        res = max(res, left + right);

        // we return height in the end
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;        
    }
};