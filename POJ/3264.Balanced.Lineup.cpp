#include <cstdio>
#include <algorithm>

const int MAXN = 50050;
int a[MAXN] = {};
const int INF = 100000000;

struct Node {
    int left, right;
    Node *l_child, *r_child;
    int max_v;
    int min_v;
    Node() : l_child(NULL), r_child(NULL), left(-1), right(-1), max_v(0), min_v(0) {}
};

Node *build_tree(int from, int to) {
    if (from > to) return NULL;
    Node *root = new Node();
    root->left = from;
    root->right = to;
    int pivot = (from + to) / 2;
    if (from == to) {
        root->l_child = NULL;
        root->r_child = NULL;
        root->max_v = a[from];
        root->min_v = a[from];
    } else {
        root->l_child = build_tree(root->left, pivot);
        root->r_child = build_tree(pivot + 1, root->right);
        root->max_v = std::max(root->l_child->max_v, root->r_child->max_v);
        root->min_v = std::min(root->l_child->min_v, root->r_child->min_v);
    }
    return root;
}

void release_tree(Node *root) {
    if (root == NULL) return;
    release_tree(root->l_child);
    release_tree(root->r_child);
    delete root;
}

bool range_query(Node *root, int from, int to, int &max_v, int &min_v) {
    if (!root) return false;
    if (to < root->left || from > root->right) return false;
    if (from <= root->left && to >= root->right) {
        max_v = root->max_v;
        min_v = root->min_v;
        return true;
    }
    else {
        int max_v1 = -INF, max_v2 = -INF;
        int min_v1 = INF, min_v2 = INF;
        bool ok1 = range_query(root->l_child, from, to, max_v1, min_v1);
        bool ok2 = range_query(root->r_child, from, to, max_v2, min_v2);
        max_v = std::max(max_v1, max_v2);
        min_v = std::min(min_v1, min_v2);
        if (ok1 || ok2) return true;
        else return false;
    }
}

int main () {
    int N, Q;
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    Node *root = build_tree(0, N - 1);
    for (int i = 0; i < Q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int x = 0, y = 0;
        range_query(root, a - 1, b - 1, x, y);
        printf("%d\n", x - y);
    }
    release_tree(root);
    return 0;
}

/*
Sample Input

6 3
1
7
3
4
2
5
1 5
4 6
2 2

Sample Output

6
3
0*/