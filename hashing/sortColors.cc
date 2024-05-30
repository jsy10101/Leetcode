// Algo intuition
//      make a hashmap with counts for each color
//      modify the values at indices from 0 to n according to counts of colors

// Time: O(n)
// Space: O(1) // since there colors at max
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> counts;

        for (auto num : nums) {
            counts[num] += 1;
        }

        int colorCount = 0;
        for (int i = 0; i < nums.size();) {
            if (counts[colorCount] == 0) {
                colorCount++;
            }
            if (counts[colorCount] != 0) {
                nums[i] = colorCount;
                counts[colorCount]--;
                ++i;
            }
        }
    }
};
