// Time: O(n)
// Space: O(1)
// Algo intuition:
//      We apply a greedy strategy and start from (n - 1)
//      set goal = n - 1
//      then we iterate from n - 2. if the current max jump can reach goal,
//          we can update the goal to current index
//      In the end if we reach 0, we return true
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            int goal = n - 1;
    
            for (int i = n - 2; i >= 0; --i) {
                if (nums[i] + i >= goal) {
                    goal = i;
                }
            }
    
            return goal == 0;
        }
    };