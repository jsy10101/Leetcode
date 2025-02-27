// Time: O(n)
// Space: O(n)
class Solution {
    public:
        bool isAnagram(string s, string t) {
            // first check the lengths, if not equal return false;
            // then create a map from s including counts,
            // if any letter is not used in the end return false;
    
            if (s.size() != t.size()) return false;
    
            unordered_map<char, int> map;
    
            for (auto ch: s) {
                map[ch]++;
            }
    
            for (auto ch: t) {
                map[ch]--;
                if (map[ch] < 0) return false;
            }
    
            return true;
        }
    };