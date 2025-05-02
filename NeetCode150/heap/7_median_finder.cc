// Time: O(log n) for adding element in stream
// Space: O(n)
// Algo intuition:
//      - we create two heaps
//      - maxHeap (lo) and minHeap (hi)
//      - as the name suggests, the maxHeap contains all the lower healf of the elements
//      - minHeap (hi) contains all the upper half of the elements in datastream
//      - by default we keep the elements in "lo" to be 1 more or equal to "hi"
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> hi; // minHeap
    priority_queue<int> lo; // maxHeap
public:
    MedianFinder() {}
    
    // Time: O(log n)
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();

        if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }

        // cout << "lo top: " << lo.top() << endl;
        // if (!hi.empty()) {
        //     cout << "hi.top: " << hi.top() << endl;
        // }
        // cout << endl;
    }
    
    // Time: O(1)
    double findMedian() {
        if (lo.size() > hi.size()) {
            return lo.top();
        }

        return (lo.top() + hi.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */