// Time: O(n)
// Space: O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // base case: nums.size() = 0
        if (k < 1 || k > nums.size()) return 0;

        // fixed length subarray
        int left = 0;
        int sum = 0;

        for(int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double maxAvg = double(sum)/k;

        for(int right = k; right < nums.size(); ++right) {
            sum -= nums[left];
            left++;
            sum += nums[right];
            maxAvg = max(maxAvg, double(sum)/k);
        }
        return maxAvg;
    }
};
