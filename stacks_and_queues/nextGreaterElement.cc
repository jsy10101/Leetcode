// Algo intuition
//      We will maintain a monotonically decreasing stack of indices where indices correspond to max element so far

// Time: O(nums2.length)
// Space: O(nums1.length)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums2.size(); ++i) {
            while (!stack.empty() && nums2[stack.top()] < nums2[i]) {
                int j = stack.top();
                map[nums2[j]] = nums2[i];
                stack.pop();
            }
            stack.push(i);
        }
        
        vector<int> ans;
        
        for (const int& num: nums1) {
            if (map.find(num) != map.end()) {
                ans.push_back(map[num]);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};
