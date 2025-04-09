// Time: O(1) for each operation get and put
// Space: O(capacity) for cache
// Algo intuition
//      - we need cache or hash map to store [key, node->val]
//      - we will use doubly linked list to store the MRU and LRU elements in order to maintain order
//      - design choice -> by having left and right pointers, we can remove and add elements in O(1) time

class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    unordered_map<int, Node*> cache;
    int cap;
    Node* left;
    Node* right;

    // remove any element from doubly linked list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // insert Most recently used on right
    void insert(Node* node) {
        Node* prev = right->prev;
        node->next = right;
        node->prev = prev;
        right->prev = node;
        prev->next = node;
    }

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->cache.clear();
        this->left = new Node(0, 0);
        this->right = new Node(0, 0);
        this->left->next = right;
        this->right->prev = left;
    }
    
    int get(int key) {
        if (this->cache.find(key) != this->cache.end()) {
            Node* node = this->cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (this->cache.find(key) != this->cache.end()) {
            remove(this->cache[key]);
        }
        Node* newNode = new Node(key, value);
        this->cache[key] = newNode;
        insert(newNode);

        if (cache.size() > this->cap) {
            // get lru element and remove the LRU key, val from both doubly linked list and cache
            Node* lru = this->left->next;
            remove(lru);
            this->cache.erase(lru->key);
            delete lru;
        }
    }

    ~LRUCache(){
        cache.clear();
        Node* cur = left->next;
        while(cur != right){
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        delete left;
        delete right;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */