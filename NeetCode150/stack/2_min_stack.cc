// Time: O(1)
// Space: O(n)
// Algo intution:
//      - maintain two stacks, minStack and normal stack
//      - always push the min val to minStack
//      - pop from both min and normal stack
//      - for top, return stack.top()
//      - for getMin, return minStack.top()
class MinStack {
    private:
        std::stack<int> stack;
        std::stack<int> minStack;
    public:
        MinStack() {
            
        }
        
        void push(int val) {
            stack.push(val);
            val = std::min(val, minStack.empty() ? val : minStack.top());
            minStack.push(val);
        }
        
        void pop() {
            stack.pop();
            minStack.pop();
        }
        
        int top() {
            return stack.top();
        }
        
        int getMin() {
            return minStack.top();
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */