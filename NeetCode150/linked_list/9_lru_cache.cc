// Time: O(1)
// Space: O(n)
// Algo intuition:
//      create a hash map to store key value pairs to achieve O(1) avg time
//      complexity for putting and getting in general use a maxCap variable to
//      keep track of capacity of the hashMap next challenge -> identify which
//      is the least recently used key what if we use a linked list, max size of
//      linked list would be maxCap

// [00 <-> 01], newNode = 02
// prev = right->prev = 00
// prev->next = newNode (02)
// newNode->prev = prev (01)
// [00 <-> 02]
// newNode->next = right
// [00 <-> 02 -> 01]
// right->prev = newNode
// [00 <-> 02 <-> 01]
class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};