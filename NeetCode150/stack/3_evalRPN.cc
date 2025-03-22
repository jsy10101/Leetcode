// Time: O(n)
// Space: O(n)
// Algo intuition:
//      general intuition is to use a stack
//      - push onto stack if we have a number
//      - if not number, pop top two numbers, first num would be b, second a
//      - process intermediate result (a (operand) b) 
//      // handle edge cases, division by 0
//      - for division case, we take floor or truncate to 0 (normal int division)
class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            // init a stack
            // parse the tokens, push to stack, pop from stack and then push intermediate results to ans
            
            int ans = 0;
            stack<int> stack;
    
            for (const string &ex: tokens) {
                int a = 0;
                int b = 0;
    
                if (ex == "+") {
                    b = stack.top();
                    stack.pop();
                    a = stack.top();
                    stack.pop();
                    stack.push(a + b);
                } else if (ex == "-") {
                    b = stack.top();
                    stack.pop();
                    a = stack.top();
                    stack.pop();
                    stack.push(a - b);
                } else if (ex == "*") {
                    b = stack.top();
                    stack.pop();
                    a = stack.top();
                    stack.pop();
                    stack.push(a * b);
                } else if (ex == "/") {
                    b = stack.top();
                    stack.pop();
                    a = stack.top();
                    stack.pop();
                    stack.push(a / b);
                } else {
                    int num = stoi(ex);
                    stack.push(num);
                }
            }
    
            return stack.top(); 
        }
    };