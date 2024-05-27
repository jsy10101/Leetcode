// Time: O(n) where n is the length of the greater of the two ransomNote or magazine
// Space: O(1) (since letter of alphabet = 26 = constant)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // base case if len of ransomeNote is greater than magazine return false
        // create a hashMap for magazine with letter counts
        // iterate through characters of ransomNote and subtract val from map of magazine
        // return false if value of magazine reaches -1
        
        unordered_map<char, int> counts;
        for (const char& ch: magazine) {
            counts[ch]++;
        }
        
        for (const char& ch: ransomNote) {
            if (!counts[ch] || counts[ch] < 0) {
                return false;
            }
            counts[ch]--;
        }
        return true;
    }
};
