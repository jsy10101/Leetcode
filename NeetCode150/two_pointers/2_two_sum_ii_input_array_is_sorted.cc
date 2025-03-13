// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // if input is sorted, we can initialize two pointers, beg and end;
        // beg = 0;
        // end = num - 1;
        // if num[beg] + num[end] > target, end--;
        // else if num[beg] + num[end] < target, beg++;
        // else return {beg, end}

        int beg = 0;
        int end = numbers.size() - 1;

        while (beg <= end) {
            if (numbers[beg] + numbers[end] > target) {
                end--;
            } else if (numbers[beg] + numbers[end] < target) {
                beg++;
            } else {
                return {beg + 1, end + 1};
            }
        }

        return {-1, -1};
    }
};