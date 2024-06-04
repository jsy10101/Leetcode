// Algo intuition:
//      make a string ans and use it as a stack
//      store the prev character and check whether it was lower or upper.
//      make a boolean to store the lower = true/false for the prev character
//      Accordingly check if the current character (if prev was lower), is current upper and tolower(curr) == stack.top(), if yes, pop, otherwise pop


// Time: O(n)
// Space: O(n)
class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        
        // for (const char& ch: s) {
        //     if (ans != "") {
        //         if (tolower(ch) == tolower(ans.back())) {
        //             if (isupper(ans.back()) && islower(ch) || islower(ans.back()) && isupper(ch)) {
        //                 ans.pop_back();
        //             } else {
        //                 ans.push_back(ch);
        //             }
        //         } else {
        //             ans.push_back(ch);
        //         }
        //     } else {
        //         ans.push_back(ch);
        //     }
        // }

        // concise version
        for (const char& ch: s) {
            // to check if two characters are equal and one if capital and one is small
            // a = 97, A = 65
            // abs('a' - 'A') == abs('A' - 'a') == 32
            if (!ans.empty() && abs(ch - ans.back()) == 32) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};
