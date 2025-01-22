// Time: O(n * log k)
// Space: O(n + k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        // O(n)
        for (int num: nums) {
            counts[num]++;
        }

        priority_queue<pair<int, int>> heap;
        // we have to maintain size k for heap;
        // O(n * log k)
        // at most size of heap is k
        for (auto [key, val]: counts) {
            heap.push({-val, key});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> ans;
        // O(k * log k)
        while (heap.size() > 0) {
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
    }
};