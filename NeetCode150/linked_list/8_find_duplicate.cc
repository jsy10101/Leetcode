// Time: O(n)
// Space: O(1)
// Algo intuition:
//      LEARN THIS PROBLEM (prolly a leetcode hard)
//      - Linked List Cycle + Floyd's Algorithm
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }
    }
};


/**** ALTERNATE SOLUTION ****/
// Time: O(n)
// Space: O(1)
// Algo intuition:
//      negative marking
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) {
                return abs(num);
            }
            nums[idx] *= -1;
        }
        return -1;
    }
};