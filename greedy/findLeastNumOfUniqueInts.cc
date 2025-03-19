// Time: O(n log n)
// Space: O(n)
class Solution {
    public:
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            unordered_map<int, int> counts;
            for (int num: arr) {
                counts[num]++;
            }
            
            vector<int> ordered;
            for (auto [key, val]: counts) {
                ordered.push_back(val);
            }
            
            sort(ordered.begin(), ordered.end(), greater<int>());
            while (k > 0) {
                int val = ordered.back();
                if (val <= k) {
                    k -= val;
                    ordered.pop_back();
                } else {
                    break;
                }
            }
            
            return ordered.size();
        }
    };