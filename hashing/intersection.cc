// Time: O(m * (n + log m))
//		 - O(n*m) to fill up hashmap
//		 - O(m log m) time to sort since there can atmost m elements inside ans
//		 - Total: O(m * (n + log m))
// Space: O(m * n)
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> counts;
        for (vector<int>& arr: nums) {
            for (int x: arr) {
                counts[x]++;
            }
        }

        int n = int(nums.size());
        vector<int> ans;
        for (auto [key, val]: counts) {
            if (val == n) {
                ans.push_back(key);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
