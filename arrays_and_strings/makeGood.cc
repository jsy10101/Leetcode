// Algo intuition;
//      Two pointers approach (most optimized)
//      manipulate the existing string (hence constant space complexity
//      if you find a bad pair remove decrease end counter
//      hence, we essentially re-write the string with only the good character and
//          return the substr of length (0, end)

// Time: O(n)
// Space: O(1)

class Solution {
public:
    string makeGood(string s) {
        int end = 0;

        for (int curr = 0; curr < s.size(); ++curr) {
            // bad pair
            if (end > 0 && abs(s[curr] - s[end - 1]) == 32) {
                end--;
            } else {
                s[end] = s[curr];
                end++;
            }
        }

        return s.substr(0, end);
    }
};
