// Time: O(1) - directly manipulated the given array
// Space: O(n)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // the below uses O(n) space, we can optimize this by directly manipulating the input array
        // int n = nums.size();
        // vector<int> prefixSum = {nums[0]};
        // if (n < 1) return prefixSum;

        // prefixSum[0] = nums[0];
        // for (int i = 1; i < n; ++i) {
        //     // prefixSum[i] = nums[i] + prefixSum[i - 1];
        //     prefixSum.push_back(nums[i] + prefixSum.back());
        // }
        // return prefixSum;
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
