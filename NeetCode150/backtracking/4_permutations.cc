// Time: O(n * n!)
class Solution {
private:
    void backtrack(vector<int>& curr, vector<int>& nums, vector<vector<int>>& ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int num: nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                backtrack(curr, nums, ans);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};

        backtrack(curr, nums, ans);

        return ans;
    }
};