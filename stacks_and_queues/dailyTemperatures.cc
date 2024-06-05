// Algo intuition:
//      We will maintain a monotonic non-increasing stack of temperature where the values stored would be the index of temperature on a particular day in the vector temperatues
//      whenever the monotonic non-increasing property is violated, we pop from the stack until the current element is greater than the top of stack (greater element means warmer temp)

// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        // initialize answer to be equal to size of temperatures with each element having default value of 0
        vector<int> ans(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                int j = stack.top();

                // (i - j) gives the distance of the element from the current warmer temperature
                ans[j] = i - j;
                stack.pop();
            }
            stack.push(i);
        }

        return ans;
    }
};
