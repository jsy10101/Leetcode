// Time: O(n)
// Space: O(1)
// Topic: Kadane's algorithm
// Algorithm intuition:
//      - basically when CURR_SUM < 0, it will TAKE AWAY or have NET LOSS affect on the next element, so we reset it
//      - declare a maxSum and currSum variable.
//      - initially currSum = 0
//      - iterate through the array and see that if current sum is negative, set it to 0
//      - Also keep track of the max sum during this time
//      - in the end return the maxSum
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for (int num : nums) {
            currSum += num;
            maxSum = max(maxSum, currSum);

            // reset currSum to 0 if currSum < 0
            if (currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }
};