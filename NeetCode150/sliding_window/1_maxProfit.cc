// Time: O(n)
// Space: O(1)
// Algo intuition:
//      we use a sliding window approach
//      start with left and right pointers
//      left = right = 0;
//      slide window if window is invalid
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int left = 0;
        
        for (int right = 0; right < prices.size(); ++right) {
            // if price[right] < price[left], we cannot buy stock, slide window to right by
            //      incrementing left pointer
            while (prices[right] < prices[left]) {
                left++;
            }
            maxP = max(maxP, prices[right] - prices[left]);
        }

        return maxP;
    }
};