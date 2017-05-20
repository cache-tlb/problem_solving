#include <map>
#include <cstdlib>
#include <cstdio>

class LRUCache {
public:
    struct Node {
        int data, key;
        Node *prev, *next;
        Node(): prev(NULL), next(NULL), data(-1), key(-1) {}
        void detach() {
            if (prev) prev->next = next;
            if (next) next->prev = prev;
            prev = NULL;
            next = NULL;
        }
        void attach_next(Node *host) {
            Node *old_next = host->next;
            host->next = this;
            if (old_next) old_next->prev = this;
            prev = host;
            next = old_next;
        }
        void attach_prev(Node *host) {
            Node *old_prev = host->prev;
            host->prev = this;
            if (old_prev) old_prev->next = this;
            prev = old_prev;
            next = host;
        }
    };

    struct BiDirList {
        Node *head, *tail;
        BiDirList() {
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->prev = head;
        }
        void push_front(Node *node) {
            node->attach_next(head);
        }
        void push_back(Node *node) {
            node->attach_prev(tail);
        } 
        Node* front() {
            if (head->next != tail) return head->next;
            return NULL;
        }
        Node* back() {
            if (tail->prev != head) return tail->prev;
            return NULL;
        }
        Node* pop_front() {
            Node *node = front();
            if (node) node->detach();
            return node;
        }
        Node* pop_back() {
            Node *node = back();
            if (node) node->detach();
            return node;
        }
    };

    LRUCache(int capacity) : cap(capacity) {}

    Node* access_node(int key) {
        if (table.count(key) > 0) {
            Node *node = table[key];
            node->detach();
            li.push_front(node);
            return node;
        }
        return NULL;
    }
    
    int get(int key) {
        int val = -1;
        Node *node = access_node(key);
        if (node) val = node->data;
        return val;
    }

    void put(int key, int value) {
        Node *node = access_node(key);
        if (node) node->data = value;
        else {
            if (table.size() >= cap) {
                node = li.pop_back();
                int node_key = node->key;
                table.erase(node_key);
            } else {
                node = new Node();
            }
            node->key = key;
            node->data = value;
            table[key] = node;
            li.push_front(node);
        }
    }

    int cap;
    std::map<int,Node*> table;  // key -> node
    BiDirList li;
};
