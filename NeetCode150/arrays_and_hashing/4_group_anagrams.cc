// Time: O(n * m * log (m))
// Space: O(n * m)
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            // brute force
            // for word in strs
            //      sort word
            //      add it to a map(str sorted, original word)
            // in the end iterate through the map to add it to vector
            // Time:
            //     n strings
            //     length of longest string m
            //     sort = mlogm
            //     n * mlogm
    
            unordered_map<string, vector<string>> map;
            vector<vector<string>> ans;
    
            for (auto word: strs) {
                string originalWord = word;
                sort(word.begin(), word.end());
                map[word].push_back(originalWord);
            }
            
            for (auto [key, val]: map) {
                ans.push_back(val);
            }
    
            return ans;
        }
    };