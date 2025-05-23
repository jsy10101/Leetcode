// Time: O(n * log n)
// Space: O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());

        while (heap.size() > 1) {
            int first = heap.top();
            heap.pop();
            int second = heap.top();
            heap.pop();

            if (first > second) {
                heap.push(first - second);
            }
        }

        return heap.size() == 0 ? 0 : heap.top();
    }
};