
class KthLargest {
public:
    priority_queue<int> heap;
    int k
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num: nums) {
            add(num);
        }
    }
    
    // time O(n * log k)
    int add(int val) {
        heap.push(-val);
        while (heap.size() > k_constant) {
            heap.pop();
        }
        
        return -heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */