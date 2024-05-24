// Time: O(n)
// Space: O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        // approach two pointers
        // left and right pointers
        // essentially swap s[left] and s[right]

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }

    }
};
