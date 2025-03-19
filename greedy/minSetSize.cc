// Time: O(n log n)
// Space: O(n)
// Algo intuition:
//      make a counts map
//      make a heap which has the frequencies only
//      remove elements from heap with highest frequencies until array size is half 
class Solution {
    public:
        int minSetSize(vector<int>& arr) {
            int n = arr.size();
            unordered_map<int, int> counts;
    
            for (const int &num: arr) {
                counts[num]++;
            }
            
            priority_queue<int> heap;
            for (const auto &[key, val]: counts) {
                heap.push(val); 
            }
            
            int currArrSize = n;
            int ans = 0; 
            while (!heap.empty() && currArrSize > n / 2) {
                currArrSize -= heap.top();
                heap.pop();
                ans++;
            }
            
            return ans;   
        }
    };