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
// Time: O(log n) best O(n) worst
// Space: O(log n) best O(n) worst
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = 0;
        double minDiff = std::numeric_limits<double>::max();
        TreeNode* curr = root;

        while (curr != NULL) {
            double currDiff = target - curr->val;

            if (abs(currDiff) == abs(minDiff))
                closest = min(closest, curr->val);

            if (abs(currDiff) < abs(minDiff)) {
                minDiff = currDiff;
                closest = curr->val;
            }

            if (currDiff == 0)
                return target;

            curr = currDiff > 0 ? curr->right : curr->left;
        }

        return closest;
    }
};
