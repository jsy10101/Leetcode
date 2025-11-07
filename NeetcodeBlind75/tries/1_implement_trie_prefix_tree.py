class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False


class Trie:
    """
    Algorithm intuition:
        - we note that at each layer, we can create a new TrieNode which holds the children hash map and whether the word ends
        - initialize root as a TrieNode
        - for every new insert word, check if current character is in curr.children hash map
            - if not, create a new node
            - regardless of the above case, move to the child using curr = curr.children[c]
            - when exiting for loop mark current word as endOfWord
        - for search, same as above, iterate through the whole word and check if after exiting loop it is endOfWord
        - for prefix, same as above; if we exit the loop then return True
    Time: O(n)
    Space: O(t)
    where n = size of word, t = total trie nodes
    """

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root

        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.endOfWord = True

    def search(self, word: str) -> bool:
        curr = self.root

        for c in word:
            if c not in curr.children:
                return False
            curr = curr.children[c]

        return curr.endOfWord

    def startsWith(self, prefix: str) -> bool:
        curr = self.root

        for c in prefix:
            if c not in curr.children:
                return False
            curr = curr.children[c]

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
