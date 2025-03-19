// Time: O(n * log n)
// Space: O(log n)
class Solution {
    public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            // calculate the total output of box for each box types
            // [50, 10, 28, 27]
            // greedily choose numberOfBoxes which has highest output and truckSize < 10
            // in above example, 5 < 10 and output is 50, choose that
            // now truckSize = 5
            // now choose 4, truckSize = 1
            // output = 28, totalUnits = 78
            // now choose 3 (one box since only one truck), truckSize = 0
            // output = 3, totalUnit = 81
            // ------------- above does not work -----------------
            
            // [[5,10], [3,9], [4,7], [2,5]]
            // 50, 27, 14
            // Greedily sort the array by number of units in non-decreasing order
            struct Comparator {
                bool operator() (const vector<int> &v1, const vector<int> &v2)
                {
                    return (v1[1] > v2[1]);
                }   
            };
            
            sort(boxTypes.begin(), boxTypes.end(), Comparator());
            
            int maxUnits = 0;
            for (const auto& boxType: boxTypes) {
                if (truckSize <= 0) break;
                if (boxType[0] <= truckSize) {
                    maxUnits += (boxType[0] * boxType[1]);
                } else {
                    maxUnits += (truckSize * boxType[1]);
                }
                truckSize -= boxType[0];
            }
    
            return maxUnits;            
        }
    };