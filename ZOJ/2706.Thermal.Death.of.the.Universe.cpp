#include <cstdio>
/*
int n, m;
const int MAXN = 30010;

long long a[MAXN] = {};

struct Node {
    int left, right;
    Node *l_child, *r_child;
    int lazy_tag;
    long long value;
    Node() : l_child(NULL), r_child(NULL), left(-1), right(-1), lazy_tag(0), value(0) {}
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
        root->value = a[from];
        root->lazy_tag = 1;
    } else {
        root->l_child = build_tree(root->left, pivot);
        root->r_child = build_tree(pivot + 1, root->right);
        root->lazy_tag = 0;
    }
    return root;
}

void release_tree(Node *root) {
    if (root == NULL) return;
    release_tree(root->l_child);
    release_tree(root->r_child);
    delete root;
}

void range_set(Node *root, long long v, int from, int to) {
    if (!root) return;
    if (to < root->left || from > root->right) return;
    if (from <= root->left && to >= root->right) {
        root->lazy_tag = 1;
        root->value = v;
    } else {
        if (root->lazy_tag) {
            if (root->l_child) {
                root->l_child->value = root->value;
                root->l_child->lazy_tag = 1;
            }
            if (root->r_child) {
                root->r_child->value = root->value;
                root->r_child->lazy_tag = 1;
            }
        }
        range_set(root->l_child, v, from, to);
        range_set(root->r_child, v, from, to);
        root->lazy_tag = 0;
    }
}

long long range_sum(Node *root, int from, int to, long long derived) {
    if (!root) return 0;
    if (to < root->left || from > root->right) return 0;
    if (from <= root->left && to >= root->right && root->lazy_tag == 1) {
        return (derived < 0 ? root->value : derived) * (root->right - root->left + 1);
    }
    else {
        if (derived < 0 && root->lazy_tag == 1) derived = root->value;
        return range_sum(root->l_child, from, to, derived) + range_sum(root->r_child, from, to, derived);
    }
}

void range_flush(Node *root, int from, int to) {
    if (!root) return;
    if (to < root->left || from > root->right) return;
    if (from <= root->left && to >= root->right && root->lazy_tag == 1) {
        for (int i = root->left; i <= root->right; i++) {
            a[i] = root->value;
        }
    } else {
        range_flush(root->l_child, from, to);
        range_flush(root->r_child, from, to);
    }
}

void print_node(Node *root) {
    if (!root) return;
    printf("Node [from %d, to %d], value: %d\n", root->left, root->right, root->lazy_tag ? root->value : -1);
    print_node(root->l_child);
    print_node(root->r_child);
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        long long origin_sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            origin_sum += a[i];
        }
        Node *root = build_tree(1, n);
        int from, to;
        long long cur_sum = origin_sum;
        for (int k = 0; k < m; k++) {
            scanf("%d%d", &from, &to);
            // print_node(root);
            long long rs = range_sum(root, from, to, -1);
            long long cnt = to - from + 1;
            long long avg = rs / cnt;
            if (0) range_set(root, avg, from, to);
            else {
                if (cur_sum <= origin_sum && rs > 0) {
                    avg += 1;
                } else if (cur_sum > origin_sum && rs < 0) {
                    avg -= 1;
                }
                range_set(root, avg, from, to);
                cur_sum += (avg * cnt - rs);
            }
            // debug 
            // printf("range_sum: %d\n", rs);
            // range_flush(root, 1, n);
            // for (int i = 1; i <= n; i++) {
            //     if (i != 1) printf(" ");
            //     printf("%lld", a[i]);
            // }
            // printf("\n");
            // end debug 
        }
        range_flush(root, 1, n);
        for (int i = 1; i <= n; i++) {
            if (i != 1) printf(" ");
            printf("%lld", a[i]);
        }
        printf("\n");
        release_tree(root);
    }
    return 0;
} */
/* 
6 1 
1 2 3 4 5 6 
1 6 

6 2 
1 2 3 4 5 6 
2 6 
1 5 
 
 
1 1 
1  
1 1 
 
6 2  
1 1 1 3 1 1 
3 4 
4 5 
 
6 4 
1 2 3 4 5 6 
1 2 
2 6 
1 3 
2 5 
 
3 3 
-1 -1 -2 
1 2 
2 3 
1 3 
*/  

#include <stdio.h>

int main() {
    int n, m, a[30001];
    while (scanf("%d%d", &n, &m) != EOF) {
        long long ori = 0, sum = 0;
        int i, j;
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ori += a[i];
        }
        sum = ori;
        int begin, end, total;
        long long part, avr;
        for (i = 0; i < m; i++) {
            scanf("%d %d", &begin, &end);
            part = 0;
            for (j = begin; j <= end; j++)
                part += a[j];
            total = end - begin + 1;
            avr = part / total;
            if (part % total) {
                if (sum <= ori && part > 0)
                    avr++;
                else if (sum > ori && part < 0)
                    avr--;
            }
            for (j = begin; j <= end; j++)
                a[j] = avr;
            sum = sum - part + avr * total;
        }
        for (i = 1; i < n; i++)
            printf("%d ", a[i]);
        printf("%d\n\n", a[n]);
    }
    return 0;
}