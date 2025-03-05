class Solution {
    public:
        // Algo intuition
        //      Calc prefix and suffix products excluding index
        //      Final ans is prefix[i] * suffix[i]
        // nums  : [-1, 1, 0, -3, 3]
        // prefix: [1, -1, -1, 0, 0]
        // suffix: [0, 0, -9, 3, 1]
        // result: [0, 0, 9, 0, 0]
    
        /********* SOLUTION 1 *********/
        // Time: O(n)
        // Space: O(n)
        // vector<int> productExceptSelf(vector<int>& nums) {
        //     int n = nums.size();
        //     vector<int> prefix(n);
        //     vector<int> suffix(n);
        //     vector<int> res(n);
    
        //     prefix[0] = 1;
        //     suffix[n - 1] = 1;
    
        //     for (int i = 1; i < n; ++i) {
        //         prefix[i] = nums[i - 1] * prefix[i - 1];
        //     }
        //     for (int i = n - 2; i >= 0; --i) {
        //         suffix[i] = nums[i + 1] * suffix[i + 1];
        //     }
        //     for (int i = 0; i < n; ++i) {
        //         res[i] = prefix[i] * suffix[i];
        //     }
    
        //     return res;
        // }
    
        /********* SOLUTION 2 - OPTIMAL *********/
        // Time: O(n)
        // Space: O(1) (excluding output array)
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n, 1);
            
            for (int i = 1; i < n; ++i) {
                res[i] = res[i - 1] * nums[i - 1];
            }
    
            int postfix = 1;
            for (int i = n - 1; i >= 0; --i) {
                res[i] *= postfix;
                postfix *= nums[i];
            }
    
            return res;
        }
    
    };