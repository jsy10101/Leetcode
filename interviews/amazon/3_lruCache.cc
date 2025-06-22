// Time: O(1) for each operation get and put
// Space: O(n) for hash map and linked list
// Topics: hashing (hash maps), linked list (doubly linked-list), system design

// Algo intuition
//      - use a hashmap (cache) to store keys and a link to a Node
//      - Node refers to a Node in our doubly linked list
//      - we can use this to insert and remove a give node in O(1) time
//      - convention: doubly-ended-linked list -> LRU front, MRU back

// doubly-linked list
class Node {
   public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void insert(Node* node) {
        Node* prev = tail->prev;
        node->next = tail;
        node->prev = prev;
        prev->next = node;
        tail->prev = node;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

   public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    // destructor to free nodes and cache
    ~LRUCache() {
        cache.clear();
        Node* curr = head->next;

        while (curr != tail) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        delete head;
        delete tail;
    }

    int get(int key) {
        if (cache.contains(key)) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            remove(cache[key]);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);

        if (cache.size() > cap) {
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);

            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */