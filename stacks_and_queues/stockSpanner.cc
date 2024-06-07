// Algo intuition:
//      we will make a pair<int, int> which represents {top element price, num of elements less than or equal to that price}
//      we maintiain a monotonic non-decreasing stack

// Time: O(1) amortized
// Space: O(n)
class StockSpanner {
    // pair<int, int> -> [{price at top}, {num of elements less than or equal to top}]
    stack<pair<int, int>> stack;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        // below while loop runs n number of iterations max or in total hence average run time of O(1) amortized
        while (!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }
        stack.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
