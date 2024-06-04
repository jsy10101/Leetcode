// Time: O(1) amortized
// Space: O(1) since max size of queue can be O(3000) = O(1)
class RecentCounter {
public:
    queue<int> queue;
    RecentCounter() {
        
    }
    int ping(int t) {
        // in the worst case the below loop can run 3000 times, which is constant and hence O(1)
        while (!queue.empty() && queue.front() < t - 3000) {
            queue.pop();
        }
        queue.push(t);
        return queue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
