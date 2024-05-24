// Time: O(n)
// Space: O(1)
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        // [1, -2, -3] -> [1, -1, -4]
        // [-3,2,-3,4,2] -> [-3, -1, -4, 0, 2]
        // now we find the min of the prefixSum and return minVal + 1 so that
        int minVal = 0;
        int total = 0;
        for(int num: nums) {
            total += num;
            minVal = min(minVal, total);
        }

        return -minVal + 1;
    }
};
