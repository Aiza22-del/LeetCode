/*
146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 
Constraints:
1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

class LRUCache 
{
private:
    struct Node 
    {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) 
        {
            key = k; 
            value = v; 
            prev = nullptr; 
            next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; 
    Node* tail; 

    void addToFront(Node* node) 
    {
        node->next = head;
        node->prev = nullptr;

        if (head != nullptr) 
        {
            head->prev = node;
        }        
        head = node;
        if (tail == nullptr) 
        {
            tail = node;
        }
    }

    void removeNode(Node* node) 
    {
        if (node->prev != nullptr) 
        {
            node->prev->next = node->next;
        } 
        else 
        {
            head = node->next;
        }
        if (node->next != nullptr) 
        {
            node->next->prev = node->prev;
        } 
        else 
        {
            tail = node->prev;
        }
    }

    void moveToFront(Node* node) 
    {
        removeNode(node);
        addToFront(node);
    }

    Node* findNode(int key) 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            if (current->key == key) 
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        head = nullptr; 
        tail = nullptr;
    }

    int get(int key) 
    {
        if (cache.find(key) == cache.end()) 
        {
            return -1; 
        }

        Node* node = cache[key];
        moveToFront(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end()) 
        {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } 
        else 
        {
            if (cache.size() == capacity) 
            {
                cache.erase(tail->key);
                removeNode(tail);
            }
            Node* newNode = new Node(key, value);
            addToFront(newNode);
            cache[key] = newNode;
        }
    }

    ~LRUCache() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};