// Time: O(n * log n)
// Space: O(n)
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        if(sticks.size() <= 1) return 0;
        
        int cost = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
        
        while (minHeap.size() > 1) {
            int top = minHeap.top();
            minHeap.pop();
            int secondTop = minHeap.top();
            minHeap.pop();
            cost += top + secondTop;
            minHeap.push(top + secondTop);
        }
        
        return cost;
    }
};