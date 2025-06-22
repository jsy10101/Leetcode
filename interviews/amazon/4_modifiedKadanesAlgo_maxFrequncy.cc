// Time: O(n)
// Space: O(1)
// Topics: modified Kadane's algorithm
// Algo intuition:
//      - modified Kadane's algorithm
//      - we iterate and try to find a suitable value x (inclusive 1 to 50)
//      - we will try to see the net gain or loss an element in num contributes
//          - '+1' if num == m (common element) converted to k
//          - '-1' if num == k (net loss)
//          - '0' otherwise
//      - we will keep track of maxFreq
class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxFreq = 0;

        int kCount = 0;

        for (int num : nums) {
            if (num == k) {
                kCount++;
            }
        }

        for (int m = 1; m <= 50; ++m) {
            if (m == k) {
                // skip recounting k (already done above)
                continue;
            }
            int maxCount = INT_MIN;
            int currCount = 0;

            for (int num : nums) {
                if (num == m) {
                    currCount++;
                } else if (num == k) {
                    currCount--;
                }

                maxCount = max(maxCount, currCount);

                if (currCount < 0) {
                    currCount = 0;
                }
            }

            maxFreq = max(maxFreq, maxCount);
        }

        // return original k count plus maxFreq
        return kCount + maxFreq;
    }
};