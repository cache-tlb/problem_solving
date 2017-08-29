#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <list>

struct Node {
    std::string name;
    bool is_book;
    std::map<std::string, Node*> children;
    Node(const std::string &s) : name(s), is_book(false) {}
    bool has_children() const {return !children.empty();}
};

Node *root = NULL;

void add_node(Node *node, std::list<std::string> &path) {
    if (path.empty()) {
        node->is_book = true;
        return;
    }
    std::string s0 = path.front();
    if (node->children.count(s0) == 0) {
        node->children[s0] = new Node(s0);
    }
    path.pop_front();
    add_node(node->children[s0], path);
}

void release_node(Node *node) {
    for (std::map<std::string,Node*>::iterator it = node->children.begin(); it != node->children.end(); it++) {
        release_node(it->second);
    }
    delete node;
}

void print_node(Node *node, int depth, bool is_dir) {
    if (depth >= 0) {
        for (int i = 0; i < depth; i++) {
            std::cout << "    ";
        }
        std::cout << node->name << std::endl;
    }
    if (!is_dir) return;
    for (std::map<std::string,Node*>::iterator it = node->children.begin(); it != node->children.end(); it++) {
        Node *cnode = it->second;
        if (cnode->has_children()) print_node(cnode, depth+1, true);
    }
    for (std::map<std::string,Node*>::iterator it = node->children.begin(); it != node->children.end(); it++) {
        Node *cnode = it->second;
        if (cnode->is_book) print_node(cnode, depth+1, false);
    }
}

void solve() {
    print_node(root, -1, true);
    release_node(root);
    root = new Node("");
}
int main() {
    // freopen("input.txt", "r", stdin);
    std::string line;
    int t = 1;
    root = new Node("");
    while (getline(std::cin, line)) {
        if (line == "0") {
            std::cout << "Case " << t << ":" << std::endl;
            solve();
            t++;
        } else {
            std::istringstream iss(line);
            std::string token;
            std::list<std::string> path;
            while (getline(iss, token, '/')) {
                path.push_back(token);
            }
            add_node(root, path);
        }
    }
    return 0;
}