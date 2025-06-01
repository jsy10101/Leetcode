// Time: O(n)
// Space: O(1)
// Algo intuition:
//      [1,2,3,4,5,6,7], k = 3
//      => [5,6,7,1,2,3,4]
//      => another way to look at it is if we first reverse the entire array
//      => [7,6,5,4,3,2,1]
//      => now we only reverse the first k elements
//      => [5,6,7,4,3,2,1]
//      => then we can reverse the rest (k, n-1)
//      => [5,6,7,1,2,3,4]
//      3 passes but O(1) space with O(n) time complexity
class Solution {
    void reverse(vector<int>& nums, int beg, int end) {
        // we can use the two pointer approach
        while (beg < end) {
            int temp = nums[beg];
            nums[beg] = nums[end];
            nums[end] = temp;
            beg++;
            end--;
        }
    }

   public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // since k can be larger than n, we need to restrict it the array size
        k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};