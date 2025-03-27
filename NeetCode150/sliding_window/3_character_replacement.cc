// Time: O(n) where n = length of string
// Space: O(m) where m = number of unique characters in string
class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char, int> count;
        int res = 0;

        int left = 0;
        int maxf = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            maxf = max(maxf, count[s[right]]);

            // below checks if the window size - maxF has more flipped characters
            //   than allowed, then we increment the left pointer and at the same
            //   time decrease the frequency of the left character
            while ((right - left + 1) - maxf > k) {
                count[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }

        return res;
    }
};