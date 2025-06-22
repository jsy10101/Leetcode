// Time: O(n)
// Space: O(1)
// Topic: sliding window
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int maxProfit = 0;

        for (int right = 0; right < prices.size(); ++right) {
            while (prices[right] < prices[left]) {
                left++;
            }
            maxProfit = max(maxProfit, prices[right] - prices[left]);
        }

        return maxProfit;
    }
};