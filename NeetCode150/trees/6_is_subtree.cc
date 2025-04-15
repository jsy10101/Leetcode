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
// Time: O(m * n)
// Space: O(m + n)
// Algo intuition:
//      if subtree is null then we return true (since we can always have root == nullptr or a leaf which would contain a nullptr as it's left/right child)
//      if root is null and subtree is not then return false
//      now check if root and subtree are same tree
//      if not recursively check if the left/right subtree of root is equal to given subtree
class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if ((p == nullptr && q != nullptr) || 
            (p != nullptr && q == nullptr) ||
            (p->val != q->val)) {
            return false;
        }

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return left && right;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return true;
        }

        if (root == nullptr) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};