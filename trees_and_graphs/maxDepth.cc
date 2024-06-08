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

// Algo intuition:
//      At a given time we can only explore the left path or the right path,
//      We will store the length of the left path in left and the value of the right path in right
//      Base case, there root = null, return 0
//      in the end return max of (leftPath, rightPath) + 1
//      We do '+1' since we need to return the length of the path

// Time: O(n) since only O(1) operations are done in each step
// Space: O(n) worst case when tree is a linked list and O(log n) when each level of tree has at most 2 children and each level is full
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftPath = maxDepth(root->left);
        int rightPath = maxDepth(root->right);
        return max(leftPath, rightPath) + 1;
    }
};
