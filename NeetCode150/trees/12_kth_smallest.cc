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
//      we take advantage of the bfs property using inorder traversal
//      using inorder traveral, we always process the left subtree first (left most or smallest element)
//      since kth smallest is 1-indexed, we return arr[k-1]
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        dfs(root, arr);
        return arr[k - 1];
    }

    void dfs(TreeNode* node, vector<int> &arr) {
        if (node == nullptr) {
            return;
        }

        dfs(node->left, arr);
        arr.push_back(node->val);
        dfs(node->right, arr);
    }
};