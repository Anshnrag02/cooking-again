class ListNode {   
public:
    int key;
    int value;
    ListNode* next;
    ListNode* prev;

    ListNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    int cap;
    int len;
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> m;

    void removeNode(ListNode* n) {
        if (n->prev) n->prev->next = n->next;
        else head = n->next;

        if (n->next) n->next->prev = n->prev;
        else tail = n->prev;

        n->next = n->prev = nullptr;
    }

    void addFront(ListNode* n) {
        n->prev = nullptr;
        n->next = head;
        if (head) head->prev = n;
        head = n;
        if (!tail) tail = n;
    }

    void moveToFront(ListNode* n) {
        if (n == head) return;
        removeNode(n);
        addFront(n);
    }

public:
    LRUCache(int capacity) : cap(capacity), len(0), head(nullptr), tail(nullptr) {}

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;

        ListNode* n = it->second;
        moveToFront(n);
        return n->value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        auto it = m.find(key);
        if (it != m.end()) {
            ListNode* n = it->second;
            n->value = value;
            moveToFront(n);
            return;
        }

        ListNode* n = new ListNode(key, value);
        addFront(n);
        m[key] = n;
        len++;

        if (len > cap) {
            ListNode* del = tail;
            removeNode(del);
            m.erase(del->key);
            delete del;
            len--;
        }
    }
};