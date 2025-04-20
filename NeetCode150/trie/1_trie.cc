// Time: O(n), n = length of string
// Space: O(t), number of trie nodes in trie
// Algo intuition:
//      - create a TrieNode class which have end of word and a hashmap which stores character and the next trienode
//      - for insert, check if a character already exists in trie, if yes, move to the next
//      - if no create a new trie node
//      - when processed the entire string, mark end of word
//      - for search if a current character is not found in trie or if exited out of loop but endOfCharacter is not true return false
//      - for startsWith, just do the same as above and return true if exited out of loop

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
        root->endOfWord = false;
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            // proceed to the next trie node
            curr = curr->children[c];
        }

        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }

        return curr->endOfWord;
    }
   
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char c: prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */