// Time: O(n) -> constructing hash map
// Space: O(n)
class Solution {
public:
    int countElements(vector<int>& arr) {
        // since we need to count the number of elements, we need to create a hash map
        // create a hashMap from array and set values of key to be the number of times the number occurs
        // now iterate all elements in hashMap and for each element check if currElem + 1 is in hashMap, if yes, add val to ans;
        // in c++ default value of int val is 0
        
        unordered_map<int, int> dic;
        int ans = 0;
        
        for(auto num: arr) {
            ++dic[num];
        }
        
        for(auto [key, val]: dic) {
            if (dic.find(key + 1) != dic.end()) {
                ans += dic[key];
            }
        }
        return ans;
    }
};
