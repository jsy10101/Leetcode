// Time: O(n) 
// Space: O(n)
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        // make a hashMap storing the counts
        // store the max by iterating through hashMap whose count = 1
        // hashMap -> key: number, val: occurence
        
        unordered_map<int, int> counts;
        for (auto num: nums) {
            counts[num]++;
        }
        
        int ans = -1;
        for (auto &[key, val]: counts) {
            if (key > ans && val == 1) {
                ans = key;
            }
        }
        return ans;
    }
};
