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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>{};
        }
        vector<vector<int>> ans;
        
        bool leftToRight = true;
        
        deque<TreeNode*> queue;
        queue.push_back(root);
        
        // cout << "queue: ";
        while (!queue.empty()) {
            int nodesInCurrentLevel = queue.size();
            
            vector<int> temp;
            
            if (leftToRight) {
                for (auto it = queue.begin(); it != queue.end(); it++) {
                    temp.push_back((*it)->val);
                }
            } else {
                for (auto it = queue.rbegin(); it != queue.rend(); it++) {
                    temp.push_back((*it)->val);
                }
            }
            ans.push_back(temp);
            temp.clear();
            
            leftToRight = !leftToRight;
            
            for (int i = 0; i < nodesInCurrentLevel; ++i) {
                TreeNode* node = queue.front();
                queue.pop_front();
                
                // cout << node->val << " ";
                if (node->left) {
                    queue.push_back(node->left);
                }
                if (node->right) {
                    queue.push_back(node->right);
                }
            }
        }
        // cout << endl;
        return ans;
    }
};
