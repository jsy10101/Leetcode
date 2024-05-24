// Time: O(n)
// Space: O(1)
bool checkForTarget(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        // curr is the current sum
        int curr = nums[left] + nums[right];
        if (curr == target) {
            return true;
        }
        if (curr > target) {
            right--;
        } else {
            left++;
        }
    }

    return false;
}
