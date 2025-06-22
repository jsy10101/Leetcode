// Time: O(n)
// Space: O(1)
// Topics: Max heap
// Algo intuition:
//      - we can use a heap to insert and return most frequent element
//      - later on we have to try to rearrage the letters such that the most frequent char comes first
//      -   then some other prev character (if there is one present)
//      - we also have to push this char (prev) and it's frequency to heap if count > 0
//      - lastly set prev = the element we first popped from the heap
class Solution {
   public:
    string reorganizeString(string s) {
        vector<int> freq(26);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < freq.size(); ++i) {
            // store <freq, charFreq> in maxHeap (only push if frequency > 0)
            if (freq[i] > 0) {
                maxHeap.push({freq[i], i + 'a'});
            }
        }

        pair<int, char> prev = {0, ' '};
        string res = "";

        while (!maxHeap.empty() || prev.first > 0) {
            if (prev.first > 0 && maxHeap.empty()) {
                return "";
            }

            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            res += ch;
            count--;

            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            prev = {count, ch};
        }

        return res;
    }
};