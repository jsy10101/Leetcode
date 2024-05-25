// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // create a hashMap -> key: letter (ballon letters only), val: count of letter
        // return min of count of letters
        
        unordered_map<char, int> counts = {{'b', 0,}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
        
        for (char ch: text) {
            if (counts.find(ch) != counts.end()) {
                counts[ch]++;
            }
        }
        return min({counts['b'], counts['a'], counts['l'] / 2, counts['o'] / 2, counts['n']});
    }
};
