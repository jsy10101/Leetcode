// Time: O(n * 2^n)
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // done in order to handle duplicate elements
        sort(candidates.begin(), candidates.end());

        backtrack(0, {}, 0, candidates, target);
        return ans;
    }

private:
    void backtrack(int idx, vector<int> path, int currSum, vector<int>& candidates, int target) {
        if (currSum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            // take care of duplicate elements
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (currSum + candidates[i] > target) {
                break;
            }

            path.push_back(candidates[i]);
            backtrack(i + 1, path, currSum + candidates[i], candidates, target);
            path.pop_back();
        }
    }
};