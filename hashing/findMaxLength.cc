// Referred to solution for this
// Algo: solve it by prefixSum
// 0 -> -1 sum
// 1 -> 1 sum
// initially we will be at index -1 (since we have not started and sum would be 0)
// map: key -> sum, val -> index

// Time: O(n)
// Space: O(1)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSumMap = {{0, -1}};
        int sum = 0, ans = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 1 ? 1 : -1;
            
            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                ans = max(ans, i - prefixSumMap[sum]);
            } else {
                prefixSumMap[sum] = i;
            }
        }
        return ans;
    }
};
