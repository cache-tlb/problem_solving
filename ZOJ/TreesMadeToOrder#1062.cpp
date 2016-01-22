#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
    int nNode;
    Node *left,*right;
    Node():nNode(0),left(NULL),right(NULL){}
    Node(int _nNode):nNode(_nNode),left(NULL),right(NULL){}
};

int table[100];
int start[100];
const int MAXNODE = 20;
int n;

int node_number(int index) {
    for(int i = 0; i < MAXNODE; i++){
        if(start[i] <= index && index < start[i+1]) return i;
    }
    return MAXNODE;
}

void build_tree(Node *node, int index) {
    if(node->nNode<=1) return;
    int tot_node = node_number(index);
    int offset = start[tot_node];
    int l_node = 0;
    int sum = 0;
    for(; l_node < tot_node; l_node++) {
        if(sum + table[l_node]*table[tot_node - 1 - l_node] + offset > index) break;
        sum += table[l_node]*table[tot_node - 1 - l_node];
    }
    int r_node = tot_node - 1 - l_node;
    int l_index = (index - offset - sum) / table[r_node] + start[l_node];
    int r_index = (index - offset - sum) % table[r_node] + start[r_node];
    //printf("index: %d, tot_node: %d, l_node: %d, r_node: %d, l_index: %d, r_index: %d\n", index, tot_node, l_node, r_node, l_index, r_index);
    if(l_node){
        Node *lc = new Node(l_node);
        build_tree(lc, l_index);
        node->left = lc;
    }
    if(r_node){
        Node *rc = new Node(r_node);
        build_tree(rc, r_index);
        node->right = rc;
    }
}

void delete_tree(Node *node){
    if(!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

void print_tree(Node *node){
    if(node->left){
        printf("(");
        print_tree(node->left);
        printf(")");
    }
    printf("X");
    if(node->right){
        printf("(");
        print_tree(node->right);
        printf(")");
    }
}

void process() {
    Node *root = new Node(n);
    build_tree(root, n);
    print_tree(root);
    printf("\n");
    delete_tree(root);
}

int main(int argc, char const *argv[])
{
    table[0] = table[1] = 1;
    for(int k = 2; k < MAXNODE; k++){
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += table[i]*table[k-1-i];
        }
        table[k] = sum;
    }

    int sum = 0;
    for(int i = 0; i < MAXNODE; i++){
        sum += table[i];
        start[i+1] = sum;
    }

    while(scanf("%d", &n)){
        if(!n) break;
        process();
    }
    return 0;
}
