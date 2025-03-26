// Time: O(l) where l = length of string s
// Space: O(26) or O(1) = letters in english alphabet
// Algo intuition:
//      sliding window approach
//      declare left = right = 0
//      increment right pointer, if we encounter a duplicate character do some logic
//      we can declare a "set" to track the current characters in window,
//          space complexity of O(n) will be added but we can search for tokens in our current window in O(1) time
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int ans = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            while (set.contains(s[right])) {
                set.erase(s[left]);
                left++;
            }

            set.insert(s[right]);
            // ans would be max between ans and the sliding window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};