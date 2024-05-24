// Time: O(n)
// Space: O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int curr = 0; // stores the number of zeros

        // [1, 1, 0, 0, 1, 1, 0]

        int maxLen = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                curr++;
            }
            // reduce window size until more than k zeros
            // mistake made, increase left regardless of whether you find a zero
            while (curr > k) {
                if (nums[left] == 0) {
                    curr--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
