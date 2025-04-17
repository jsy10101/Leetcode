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
// Space: O(d) d = depth of tree
// Algo intuition:
//      just do regular bfs algo
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root); 

        while (!q.empty()) {
            int n = q.size();
            vector<int> levelElems;

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelElems.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            // once all the level elements are added, push it back to ans
            ans.push_back(levelElems);
        }

        return ans;
    }
};