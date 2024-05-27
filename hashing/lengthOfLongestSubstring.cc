// Time: O(n)
// Space: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, ans = 0;
        unordered_set<char> seen;
        
        for (int right = 0; right < s.size(); ++right) {
            // since we want a subarray, (which is contiguous) if a character repeats then we have to slide the window until we reach that particular character to shrink the subarray and start over
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};
