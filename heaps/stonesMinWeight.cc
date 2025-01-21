// Space: O(n)
// Time: O(n + k * log (n))
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        for (int pile: piles) {
            sum += pile;
        }

        priority_queue<int> heap(piles.begin(), piles.end());
        
        while (k > 0) {
            int topPile = heap.top();
            heap.pop();
            heap.push(topPile - floor(topPile/2));
            sum -= floor(topPile/2);
            --k;
        }
        
        return sum;
    }
};