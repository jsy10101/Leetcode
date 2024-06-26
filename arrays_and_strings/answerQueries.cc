// Time: O(n) - due to prefix sum
// Space: O(n)
vector<bool> answerQueries(vector<int>& nums, vector<vector<int>>& queries, int limit) {
    vector<int> prefix = {nums[0]};
    for (int i = 1; i < nums.size(); i++) {
        prefix.push_back(prefix.back() + nums[i]);
    }

    vector<bool> ans;
    for (vector<int>& query: queries) {
        int x = query[0], y = query[1];
        int curr = prefix[y] - prefix[x] + nums[x];
        ans.push_back(curr < limit);
    }

    return ans;
}
