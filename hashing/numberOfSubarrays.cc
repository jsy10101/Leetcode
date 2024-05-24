// Time: O(n)
// Space: O(n)

// very similar patter to `hashing/subarraySum.cc`, addition of `% 2` to track
//  number of odd numbers
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0, curr = 0;

        for (int num: nums) {
            curr += num % 2;
            ans += counts[curr - k];
            counts[curr] += 1;
        }

        return ans;
    }
};
