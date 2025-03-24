// Time: O(n) amortized
// Space: O(n)
// Algo intuition:
//      we see we can't operate on temperatures before we have processed later days
//      above gives us an intuition that we can use a stack to store the coldest days
//      j, represting index would top of stack
//      i - j would be the length or number of days until we have seen a warmer temp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stack;
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                int j = stack.top();
                ans[j] = i - j;
                stack.pop();
            }
            stack.push(i);
        }

        return ans;
    }
};