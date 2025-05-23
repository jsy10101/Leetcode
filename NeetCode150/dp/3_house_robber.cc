// Time: O(n)
// Space: O(1) improved from O(n)
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            // To avoid out of bounds error from setting base case
            return nums[0];
        }

        int n = int(nums.size());

        // Base cases
        int backTwo = nums[0];
        int backOne = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            // Recurrence relation
            int temp = backOne;
            backOne = max(backOne, backTwo + nums[i]);
            backTwo = temp;
        }

        return backOne;
    }
};