// Time: O(n * log k)
// Space: O(k)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> heap;

        for(const auto &point: points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            heap.push(pair(distance, point));
            
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<vector<int>> ans;

        while (heap.size() > 0) {
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
    }
};