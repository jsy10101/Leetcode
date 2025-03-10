// Time: O(n * n)
// Space: O(1) {in place}
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            // consider
            // [1,2,3]
            // [4,5,6]
            // [7,8,9]
    
            // matix.size() = number of rows = number of cols (since square matrix)
            // for the inner loop, we iterate (right - left) or n - 1 times
    
            // we want to save top left into a temp variable, called temp
            // then we move bottom left to top left
            // top bottom right to bottom left
            // top right to bottom right
            // top left (save in temp) to top right
    
            // note that we are doing n-1 rotations in every loop
            // once above is done, increment left by 1, and right by -1 to target inner square
            //      which is the boundary condition
            
            int left = 0;
            int right = matrix.size() - 1;
    
            while (left < right) {
                int top = left;
                int bottom = right; // since square matrix, rows = cols
                for (int i = 0; i < right - left; ++i) {
                    // save top left in temp
                    int topLeft = matrix[top][left + i];
    
                    matrix[top][left + i] = matrix[bottom - i][left];
                    matrix[bottom - i][left] = matrix[bottom][right - i];
                    matrix[bottom][right - i] = matrix[top + i][right];
                    matrix[top + i][right] = topLeft;
                }
    
                left++;
                right--;
            }
        }
    };