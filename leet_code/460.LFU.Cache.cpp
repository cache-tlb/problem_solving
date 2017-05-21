#include <map>
#include <cstdlib>
#include <cstdio>
#include <cassert>

using namespace std;

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

class LFUItem {
public:
    LFUItem() {}
    void add_node(Node *node) {
        assert(table.count(node->key) == 0);
        table[node->key] = node;
        li.push_front(node);
    }
    Node* remove_last() {
        Node *node = li.back();
        assert(node != NULL);
        node->detach();
        table.erase(node->key);
        return node;
    }
    Node* remove_node(int key) {
        assert(table.count(key) > 0);
        Node *node = table[key];
        node->detach();
        table.erase(key);
        return node;
    }
    int size() const {
        return table.size();
    }

    BiDirList li;
    std::map<int, Node*> table; // key -> node
};
class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity) { }
    
    int get(int key) {
        int val = -1;
        if (tf.count(key) > 0) {
            int f = tf[key] + 1;
            tf[key] = f;
            Node *node = freq_list[f-1].remove_node(key);
            if (freq_list[f-1].size() == 0) freq_list.erase(f-1);
            freq_list[f].add_node(node);
            val = node->data;
        }
        return val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        if (tf.count(key) > 0) {
            int f = tf[key] + 1;
            tf[key] = f;
            Node *node = freq_list[f-1].remove_node(key);
            if (freq_list[f-1].size() == 0) freq_list.erase(f-1);
            node->data = value;
            freq_list[f].add_node(node);
        } else {
            Node *node = NULL;
            if (tf.size() >= cap) {
                // find least f;
                int f = freq_list.begin()->first;
                node = freq_list[f].remove_last();
                if (freq_list[f].size() == 0) freq_list.erase(f);
                tf.erase(node->key);
            } else {
                node = new Node();
            }
            node->key = key;
            node->data = value;
            tf[key] = 1;
            freq_list[1].add_node(node);
        }
    }

    int cap;
    std::map<int, int> tf;  // key -> freq
    std::map<int, LFUItem> freq_list;   // freq -> items
};

