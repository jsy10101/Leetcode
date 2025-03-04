// Time: O(n log k)
// Space: O(n + k)
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> map;
            vector<int> ans;
    
            for (auto num: nums) {
                map[num]++;
            }
    
            // 1 -> 3
            // 3 -> 1
            // 2 -> 2
            priority_queue<pair<int, int>> pq;
    
            for (auto [key, val]: map) {
                pq.push({val, key});
            }
    
            while (!pq.empty() && k > 0) {
                ans.push_back(pq.top().second);
                k--;
                pq.pop();
            }
    
            return ans;
        }
    };