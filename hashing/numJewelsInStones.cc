// Time: O(n) length of stones string
// Space: O(1)
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelType;
        int ans = 0;
        
        for (const char& jewel: jewels) {
            jewelType.insert(jewel);
        }
        
        for (const char& stone: stones) {
            if (jewelType.find(stone) != jewelType.end()) {
                ans++;
            }
        }
        return ans;
    }
};
