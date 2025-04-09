// Time: O(log (m*n))
// Space: O(1)
// Algo intuition:
//      we apply binary search two times to solve in O(log m + log n) = O(log (m*n)) time
//      first we declare top and bottom vars equivalent to first and last row
//      this is to identify the potential row where our target element can be
//      if the target is bigger than the greatest element in row -> last element in row, we search in the bottom half and set top = mid + 1;
//      else if target is smaller than the smallest element in the mid row -> first element, we search in the top half and set bottom = mid - 1;
//      once we have the potential row, break
//      then apply the usual binary search algo to find if the target is present or not
//      EDGE CASE - if top > bottom, this cannot be possible and hence we can conclude that the element is not present in matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0;
        int bottom = ROWS - 1;

        while (top <= bottom) {
            int row = (top + bottom) / 2;

            if (target > matrix[row][COLS - 1]) {
                top = row + 1;
            } else if (target < matrix[row][0]) {
                bottom = row - 1;
            } else {
                break;
            }
        }

        if (!(top <= bottom)) {
            return false;
        }

        int row = (top + bottom) / 2;
        int beg = 0;
        int end = COLS - 1;

        while (beg <= end) {
            int col = (beg + end) / 2;
            if (target > matrix[row][col]) {
                beg = col + 1;
            } else if (target < matrix[row][col]) {
                end = col - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};