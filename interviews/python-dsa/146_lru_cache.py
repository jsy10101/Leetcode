class Node:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None


class LRUCache:
    """
    Algorithm intuition:
        - we basically need to use something like a double ended linked list
        - the next of head would contain the lfu element, the tail would contain the mfu element
        - therefore to check if an element exists, it's better to look at a data structure which checks time in O(1) -> use map/dictionary
        - if an element is in map, remove it from doubly linked list and add it to tail
        - while putting an element, if the current capacity of the dictionary is greater than CAP, remove lfu from dict and doubly linked list
        - we need operations to add and remove element in our double-ended linked list (define another class for it to encapsulate logic)
        - for dictionary, the structure for each element would look like this
            - (key, node)
    """

    def __init__(self, capacity: int):
        # head and tail and sentineal nodes
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.cache = {}
        self.cap = capacity

        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if key in self.cache:
            self.deleteNode(self.cache[key])
            self.addNode(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache[key].val = value
            self.deleteNode(self.cache[key])
        else:
            self.cache[key] = Node(key, value)

        if len(self.cache) > self.cap:
            lfu = self.head.next
            del self.cache[lfu.key]
            self.deleteNode(lfu)

        self.addNode(self.cache[key])

    def addNode(self, newNode: Node) -> None:
        prev = self.tail.prev
        prev.next = newNode
        self.tail.prev = newNode
        newNode.next = self.tail
        newNode.prev = prev

    def deleteNode(self, node: Node) -> None:
        prevN = node.prev
        nextN = node.next
        prevN.next = nextN
        nextN.prev = prevN


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
