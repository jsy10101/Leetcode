
class Codec {
    public:
    
        // Algo design:
        //      We can't have any character as a delimeter as that can appear in a string
        //      to encode, we store the size of the word followed by #
        //      for instance, ["hello", "worldworldworld"]
        //      "5#hello15#worldworldworld"
    
        // Encodes a list of strings to a single string.
        // Time: O(n), n = number of strings
        // Space: O(1)
        string encode(vector<string>& strs) {
            string res = "";
    
            for (auto const& word: strs) {
                res += (to_string(word.size()) + "#" + word);
            }
    
            return res;
        }
    
        // Decodes a single string to a list of strings.
        // "10#thetadelta2#hi5#hello"
        // word = "10"
        // Time: O(m)
        // Space: O(1)
        vector<string> decode(string s) {
            vector<string> res;
    
            int i = 0;
    
            while (i < s.size()) {
                string curr = "";
                while (s[i] != '#') {
                    curr += s[i];
                    i++;
                }
                // to skip #
                i++;
    
                int wordSize = stoi(curr);
                
                res.push_back(s.substr(i, wordSize));
                i += wordSize;
            }
    
            return res;
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec codec;
    // codec.decode(codec.encode(strs));