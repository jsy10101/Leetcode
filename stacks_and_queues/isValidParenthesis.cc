// Algo intuition
//     make an unordered map to store the set of matching brackets
//     make a stack and only push openining brackets to stack
//     if the current bracket pushed is a closed bracket and corresponding matching bracket exists at top of stack, then pop the top most element
//     else return false
//     base case, the stack is empty and the current bracket is a closing bracket, return false
//     in the end, outside of loop, if stack is empty, return true else false


class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> matchings = {
            { '{', '}' },
            { '(', ')' },
            { '[', ']' }
        };

        for (const char& ch: s) {
            if (matchings.find(ch) != matchings.end()) {
                stack.push(ch);
            } else {
                if (stack.empty()) {
                    return false;
                }

                char prevOpening = stack.top();
                if (matchings[prevOpening] != ch) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }
};
