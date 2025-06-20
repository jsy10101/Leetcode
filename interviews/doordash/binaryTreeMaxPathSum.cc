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
//      - post order dfs
//      - at a particular time we only take the gain from left subtree or right subtree
//      - if it is negative we just return 0
//      - base case (leaf node) return 0
//      - update maxSum if the gain from left + gain from right + root val is greater than max sum
class Solution {
   private:
    int maxSum;

    int gainFromSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int gainFromLeft = max(gainFromSubtree(root->left), 0);
        int gainFromRight = max(gainFromSubtree(root->right), 0);

        maxSum = max(gainFromLeft + gainFromRight + root->val, maxSum);

        return max(gainFromLeft + root->val, gainFromRight + root->val);
    }

   public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        gainFromSubtree(root);
        return maxSum;
    }
};