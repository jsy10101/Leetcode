// Time: 2^(T) where T = target value
class Solution {
private:
    void backtrack(vector<int>& curr, int i, int target, vector<int>& nums) {
        if (target == 0) {
            this->ans.push_back(curr);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            curr.push_back(nums[j]);
            backtrack(curr, j, target - nums[j], nums);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;

        backtrack(curr, 0, target, candidates);

        return ans;
    }
};