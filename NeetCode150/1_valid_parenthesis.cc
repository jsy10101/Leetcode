// Time: O(n), n = length of string
// Space: O(1)
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {{'}', '{'}, {']', '['}, {')', '('}};

        stack<char> bracketStack;

        for (const char& ch : s) {
            if (map.contains(ch) && !bracketStack.empty() &&
                map[ch] == bracketStack.top()) {
                bracketStack.pop();
            } else {
                bracketStack.push(ch);
            }
        }

        return bracketStack.empty();
    }
};
