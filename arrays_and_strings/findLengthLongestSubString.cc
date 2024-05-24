// Time: O(n)
// Space: O(1)
int findLength(string s) {
    // curr is the current number of zeros in the window
    int left = 0, curr = 0, ans = 0;
    for (int right = 0; right < s.size(); right++) {
        if (s[right] == '0') {
            curr++;
        }

        while (curr > 1) {
            if (s[left] == '0') {
                curr--;
            }
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}
