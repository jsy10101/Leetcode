// Time: O(L), where L is the max number of digits
// Space: O(L)
class Solution {
    public:
        int maximum69Number (int num) {
            // parse the int into a string in O(n) time, greedily change the first 6 to 9
            // above should work as nth digit is always greater than n - 1
            
            string number = std::to_string(num);
    
            for (char &digit: number) {
                if (digit == '6') {
                    digit = '9';
                    break;
                }
            }
            
            return std::stoi(number);
        }
    };