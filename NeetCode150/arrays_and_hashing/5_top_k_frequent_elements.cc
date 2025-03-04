// // Time: O(n log k)
// // Space: O(n + k)
// class Solution {
//     public:
//         vector<int> topKFrequent(vector<int>& nums, int k) {
//             unordered_map<int, int> map;
//             vector<int> ans;
    
//             for (auto num: nums) {
//                 map[num]++;
//             }
    
//             // 1 -> 3
//             // 3 -> 1
//             // 2 -> 2
//             priority_queue<pair<int, int>> pq;
    
//             for (auto [key, val]: map) {
//                 pq.push({val, key});
//             }
    
//             while (!pq.empty() && k > 0) {
//                 ans.push_back(pq.top().second);
//                 k--;
//                 pq.pop();
//             }
    
//             return ans;
//         }
//     };




/*********** MORE EFFICIENT ************/


// Time: O(n)
// Space: O(n)
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            // will be using bucket sort
            // in each bucket, index -> freq, values = arr of elements
    
            unordered_map<int, int> counts;
    
            for (int num: nums) {
                counts[num]++;
            }
    
            // bucket size = nums.size() + 1;
            vector<vector<int>> bucket(nums.size() + 1);
    
            for (auto [key, val]: counts) {
                bucket[val].push_back(key);
            }
    
            vector<int> res;
            for (int i = bucket.size() - 1; i > 0; --i) {
                for (int num: bucket[i]) {
                    if (k == res.size()) return res;
                    res.push_back(num);
                }
            }
    
            return res;
        }
    };