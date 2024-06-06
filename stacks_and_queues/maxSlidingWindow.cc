// Algo intution

//      We need to maintain a montonically non-increasing deque of indices (where index corresponds to the max element in the window)
//      Use track of the window size and accordingly push elements
//      REFERRED TO SOLUTION

// Time: O(n)
// Space: O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            // remove front if current nums[i] is greater than back of queue
            while (!queue.empty() && nums[i] > nums[queue.back()]) {
                queue.pop_back();
            }
            queue.push_back(i);

            // check if the size of window has exceeded, if yes, pop front
            if (queue.front() + k == i) {
                queue.pop_front();
            }

            // front of queue contains the largest element index
            if (i >= k - 1) {
                ans.push_back(nums[queue.front()]);
            }
        }

        return ans;
    }
};
