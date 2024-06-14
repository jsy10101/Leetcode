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
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        dfs(root, values);

        int ans = INT_MAX;
        for(int i = 1; i < values.size(); ++i) {
            ans = min(ans, values[i] - values[i - 1]);
        }
        return ans;
    }
    void dfs(TreeNode* node, vector<int>& values) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left, values);
        values.push_back(node->val);
        dfs(node->right, values);
    }
};
