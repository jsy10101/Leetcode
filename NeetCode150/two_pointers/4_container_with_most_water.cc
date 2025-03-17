// Time: O(n)
// Space: O(1)
// Algo intuition:
//      - use two pointers
//      - beg = 0, end = height.size() - 1;
//      - we want max area, increment pointer that keeps the max height
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int beg = 0;
            int end = height.size() - 1;
    
            int maxArea = 0;
    
            while (beg < end) {
                int breadth = std::min(height[beg], height[end]);
                int length = end - beg;
    
                int currArea = length * breadth;
    
                if (currArea > maxArea) {
                    maxArea = currArea;
                }
                if (height[beg] <= height[end]) {
                    beg++;
                } else {
                    end--;
                }
            }
    
            return maxArea;
        }
    };