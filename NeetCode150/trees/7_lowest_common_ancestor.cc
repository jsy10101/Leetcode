/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time: O(n) worst case and O(log n) best case
// Space: O(1)
// Algo intuition:
//      if there's split occuring at a current node, then the curron node is the LCA
//      if both p->val and q->val greater than current node val then update pointer to right
//      else update pointer to null
//      iterate till cur pointer is not null
//      if we exit out of while loop, we will not have a LCA and we return NULL
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } else if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            } else {
                return curr;
            }
        }

        return nullptr;
    }
};