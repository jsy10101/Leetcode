class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False


class WordDictionary:
    """
    Algorithm intuition:
        - we use tries to solve this problem
        - adding word is trivial
            - create a root trieNode, curr as pointer (start with root)
            - iterate through the whole word and mark endOfWord once iterated through the whole word
        - for search, start with self.root and curr pointer
            - for normal case (not .) if curr character while iterating through word is not in Trie -> return False
            - in the '.' case, we need to check every possible child TrieNode to see if the word exists
                - do a dfs to achieve this, keep track of index and TrieNode in dfs
    Time: O(n) since . can be atmost twice and for that we do O(26^2) = O(1)
    Space: O(t)
    """

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root

        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]

        curr.endOfWord = True

    def search(self, word: str) -> bool:
        def dfs(j, root):
            curr = root

            for i in range(j, len(word)):
                c = word[i]

                if c == ".":
                    for child in curr.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False
                elif c not in curr.children:
                    return False
                curr = curr.children[c]

            return curr.endOfWord

        return dfs(0, self.root)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
