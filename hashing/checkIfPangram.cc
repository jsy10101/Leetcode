// Time: O(n)
// Space: O(m)
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> seen(sentence.begin(), sentence.end());
        
        // type conversion, ASCII value of 'a' = 97
        // search for lower case for every character in set
        // if a character is not found it is not a panagram
        
        for(char ch = 97; ch < 97 + 26; ++ch) {
            if (seen.find(ch) == seen.end()) return false;
        }
        return true;
    }
};
