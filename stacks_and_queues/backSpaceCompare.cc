// Algo intuition
//      we can use a string "ans" as a stack
//      we continuously push the current character to the stack if the current
//      character is not # if current character is # and stack is not empty, we
//      pop the top character from the stack

// Time: O(n)
// Space: O(n)
class Solution {
    string buildString(string s) {
        string ans = "";
        for (const char& c : s) {
            if (c == '#' && !ans.empty()) {
                ans.pop_back();
            } else if (c != '#') {
                ans.push_back(c);
            }
        }
        return ans;
    }

public:
    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }
};
