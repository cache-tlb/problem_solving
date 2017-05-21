#include <cstdio>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

// struct Interval {
//     int start;
//     int end;
//     Interval() : start(0), end(0) {}
//     Interval(int s, int e) : start(s), end(e) {}
// };

class SummaryRanges {
public:
    struct Node {
        int start, end;
        Node *prev, *next;
        Node(): prev(NULL), next(NULL), start(-1), end(-1) {}
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
    /** Initialize your data structure here. */
    SummaryRanges() {}
    Node* try_merge(Node *small, Node *large) {
        if (small->start <= large->start && large->end <= small->end) {
            large->detach();
            table.erase(large->start);
            delete large;
            return small;
        }
        if (large->start - small->end == 1) {
            large->detach();
            table.erase(large->start);
            small->end = large->end;
            delete large;
            return small;
        }
        return large;
    }


    void addNum(int val) {
        if (table.count(val) > 0) return;
        Node *node = new Node();
        node->start = val;
        node->end = val;
        table[val] = node;
        std::map<int, Node*>::iterator ub = table.upper_bound(val);
        Node *lb = NULL;
        if (ub == table.end()) {
            lb = li.back();
        } else {
            lb = ub->second->prev;
            if (lb->start < 0) lb = NULL;
        }
        if (!lb) {
            li.push_front(node);
        } else {
            node->attach_next(lb);
        }
        // try merge
        Node *prev_node = node->prev, *next_node = node->next;
        if (prev_node->start >= 0) node = try_merge(prev_node, node);
        if (next_node->start >= 0) node = try_merge(node, next_node);
    }
    
    vector<Interval> getIntervals() {
        std::vector<Interval> ret;
        for (std::map<int, Node*>::iterator it = table.begin(); it != table.end(); it++) {
            Node *node = it->second;
            ret.push_back(Interval(node->start, node->end));
        }
        return ret;
    }

    BiDirList li;
    std::map<int, Node*> table;
};
