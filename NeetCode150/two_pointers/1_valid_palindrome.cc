class Solution {
    public:
        // Time: O(n)
        // Space: O(1)
        bool isPalindrome(string s) {
            int beg = 0;
            int end = s.size() - 1;
    
            while (beg <= end) {
                if (isalnum(s[beg]) && isalnum(s[end])) {
                    if (tolower(s[beg]) != tolower(s[end])) {
                        return false;
                    }
                    beg++;
                    end--;
                } else if (isalnum(s[beg]) && !isalnum(s[end])) {
                    end--;
                } else if (!isalnum(s[beg]) && isalnum(s[end])) {
                    beg++;
                } else {
                    beg++;
                    end--;
                }
            }
    
            return true;
        }
    };