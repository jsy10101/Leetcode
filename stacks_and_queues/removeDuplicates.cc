// Algo intuition
//      Since we have to remove adjacent elements and we may not be able to do so until we have iterated some of the elements, we can recognize that this is a LIFO pattern, hence we can use a stack
//      given a char, we check the top of the stack, if not empty we compare the top with current character in s,
//      if current character is equal to top of stack we remove it else insert it in stack
//      in C++, strings are mutable so we can use them as a stack

// Time: O(n)
// Space: O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        // Strings in C++ are mutable, use the answer as a stack directly
        string ans = "";

        for(const char& ch: s) {
            // ans.back() is equivalent to stack.top() since LIFO
            if (!ans.empty() && ans.back() == ch) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};
