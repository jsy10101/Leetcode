// Time: O(n)
// Space: O(1)
// Topics: two pointers
// Algo intuition:
//      - we can use a two pointer approach
//      - compute maxLeft and maxRight
//      - the amount of water we can store at a current cell would be whatever the min of left max and right max is - height[i]
class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }

        int left = 0;
        int right = height.size() - 1;

        int leftMax = height[left];
        int rightMax = height[right];

        int res = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                res += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                res += rightMax - height[right];
            }
        }

        return res;
    }
};