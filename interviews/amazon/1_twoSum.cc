// Time: O(n)
// Space: O(n)
// Topic: hashmap
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            if (map.contains(target - nums[i])) {
                int complement = target - nums[i];
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }

        return {-1, -1};
    }
};