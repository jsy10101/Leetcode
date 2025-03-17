// Time: O(n * log n)
// Space: O(log n)
// Algo intuition:
//      here the order of elements doesn't matter
//      we can greedily sort the array in O(n log n)
//      then take all the elements in range (x + k) where x is the smallest element
class Solution {
    public:
        int partitionArray(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
    
            if (nums.size() < 1) return 0;
    
            int ans = 1;
            int smallestElem = nums[0];
            
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] - smallestElem > k) {
                    ans++;
                    smallestElem = nums[i];
                }
            }
    
            return ans;
        }
    };