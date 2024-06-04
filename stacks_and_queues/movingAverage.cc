// Algo intuition:
//      The size passed in MovingAverage determines the max size of the queue
//      add elements to the queue and return their average
//      if maxElement size is exceeded pop the front();

// Time: O(1)
// Space: O(n) where n = size of Moving Average
class MovingAverage {
public:
    queue<int> queue;
    int maxSize = 0;
    int sum = 0;
    
    MovingAverage(int size) {
        maxSize = size;
    }
    
    double next(int val) {
        
        if (queue.size() == maxSize) {
            sum -= queue.front();
            queue.pop();
        }
        
        queue.push(val);
        sum += queue.back();
        
        return double(sum) / queue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
