#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <map>
#include <climits>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    int count;
    std::vector<Node*> child;
    Node() : count(0), child(26, NULL) {}
};

void build_trie(Node *node, char *str) {
    node->count++;
    if (*str) {
        int child_id = *str-'a';
        if (!node->child[child_id]) {
            node->child[child_id] = new Node;
        }
        build_trie(node->child[child_id], &str[1]);
    }
}

int find(Node *node, char *str) {
    if (*str == 0) {
        return node->count;
    }
    int child_id = *str-'a';
    if (!node->child[child_id]) return 0;
    return find(node->child[child_id], &str[1]);
}

int main(int argc, char const *argv[])
{
    // freopen("input.txt","r",stdin);
    int n_dict, n_query;
    char buf[128];
    scanf("%d", &n_dict);
    Node *root = new Node;
    for (int i = 0; i < n_dict; i++) {
        scanf("%s", buf);
        build_trie(root, &buf[0]);
    }
    scanf("%d", &n_query);
    for (int j = 0; j < n_query; j++) {
        scanf("%s", buf);
        int res = find(root, buf);
        printf("%d\n", res);
    }
    return 0;
}