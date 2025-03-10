// Time: O(m * n)
// Space: O(1) (not considering size of return val)
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            // The idea is to set boundaries
            // first we iterate the top row
            // then right col
            // then bottom row
            // lastly, left col
    
            // we only do so till we are in bounds
            // break condition: left < right && top < bottom
            // to make things easier to code, we keep right and bottom 1 extra
    
            int left = 0;
            int right = matrix[0].size();
            int top = 0;
            int bottom = matrix.size();
            
            vector<int> ans;
    
            while (left < right && top < bottom) {
                // iterate through top row then change top boundary (increase)
                for (int i = left; i < right; ++i) {
                    ans.push_back(matrix[top][i]);
                }
                top++;
    
                // iterate through right col then change right boundary (decrease)
                for (int i = top; i < bottom; ++i) {
                    ans.push_back(matrix[i][right - 1]);
                }
                right--;
                
                // Super important, without this, we may have boundaries such as top = bottom
                //      therefore no boundary
                if (!(left < right && top < bottom)) {
                    break;
                }
                
                
                // iterate through bottom row then change bottom boundary (decrease)
                for (int i = right - 1; i >= left; --i) {
                    ans.push_back(matrix[bottom - 1][i]);
                }
                bottom--;
    
                // iterate through left col then change left boundary (increase)
                for (int i = bottom - 1; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            return ans;
        }
    };