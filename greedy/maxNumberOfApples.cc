// // Time: O(n * log n)
// // Space: O(log n)
// // Algo intuition:
// //      since we want to maximize number of apples we can greedily choose the minimum weight apple
// class Solution {
// public:
//     int maxNumberOfApples(vector<int>& weight) {
//         const int THRESHOLD = 5000;
        
//         sort(weight.begin(), weight.end());
//         int currWeight = 0;
//         int maxNumApples = 0;

//         for (const int& w: weight) {
//             if (currWeight + w > THRESHOLD) {
//                 break;
//             } 
//             currWeight += w;
//             maxNumApples++;
//         }
        
//         return maxNumApples; 
//     }
// };

// Min heap solution
class Solution {
    public:
        int maxNumberOfApples(vector<int>& weight) {
            priority_queue<int, vector<int>, greater<int>> heap(weight.begin(), weight.end());
    
            int ans = 0;
            int units = 0;
            while(!heap.empty() && heap.top() + units <= 5000) {
                units += heap.top();
                heap.pop();
                ans++;
            }
    
            return ans;
        }
    };