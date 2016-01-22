#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 512;

struct Node {
    Node *LU, *RU, *LB, *RB;
    int x1, x2, y1, y2;
    bool same, val;
    Node(){LU=NULL;RU=NULL;LB=NULL;RB=NULL;}
};

int n;

int matrix[MAXN][MAXN];

Node* build_tree(int xmin, int xmax, int ymin, int ymax){
    //printf("%d %d %d %d\n", xmin, xmax, ymin, ymax);
    if(xmin > xmax || ymin > ymax) return NULL;
    Node *node = new Node;
    node->x1 = xmin; node->x2 = xmax;
    node->y1 = ymin; node->y2 = ymax;
    int xmid = (xmin+xmax)/2, ymid = (ymin+ymax)/2;
    if(xmin==xmax && ymin==ymax) return node;
    node->LU = build_tree(xmin, xmid, ymin, ymid);
    node->RU = build_tree(xmid+1, xmax, ymin, ymid);
    node->LB = build_tree(xmin, xmid, ymid+1,ymax);
    node->RB = build_tree(xmid+1, xmax, ymid+1, ymax);
    return node;
}

void calculate(Node *node){
    if(!node) return;
    if(node->x1==node->x2 && node->y1==node->y2) {
        node->same = true;
        node->val = matrix[node->y1][node->x1];
        return;
    }
    calculate(node->LU);
    calculate(node->RU);
    calculate(node->LB);
    calculate(node->RB);
    if(!node->LU->same || !node->RU->same || !node->LB->same || !node->RB->same){
        node->same = false;
        return;
    }
    if(node->LU->val != node->RU->val || node->LB->val != node->RB->val){
        node->same = false;
        return;
    }
    if(node->LU->val != node->LB->val){
        node->same = false;
        return;
    }
    node->val = node->LU->val;
    node->same = true;
}

void release_tree(Node *node){
    if(node==NULL) return;
    release_tree(node->LU);
    release_tree(node->RU);
    release_tree(node->LB);
    release_tree(node->RB);
    //printf("%08x\n", node);
    delete node;
}

void print_tree(Node *node){
    if(!node) return;
    print_tree(node->LU);
    print_tree(node->LB);
    print_tree(node->RU);
    print_tree(node->RB);
    printf("%d %d\n", node->val, node->same);
}

int main(int argc, char const *argv[])
{
    int k;
    scanf("%d", &k);
    while(k--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                scanf("%d", &matrix[i][j]);
            }
        }
        Node *root = build_tree(0,n-1,0,n-1);
        calculate(root);
        std::vector<int> vres;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            if(node->same){
                vres.push_back(0);
                vres.push_back(node->val);
            }
            else{
                vres.push_back(1);
                q.push(node->LU);
                q.push(node->RU);
                q.push(node->LB);
                q.push(node->RB);
            }
        }
        int sz = vres.size();
        int rem = sz%4;
        int pos = rem;
        if(rem){
            int vv = 0;
            if(rem == 3){
                vv = vres[0] << 2;
                vv += vres[1] << 1;
                vv += vres[2];
            }
            else if(rem == 2){
                vv += vres[0] << 1;
                vv += vres[1];
            }
            else vv = vres[0];
            printf("%x", vv);
        }
        for(; pos < sz; pos += 4){
            int vv = vres[pos] << 3;
            vv += vres[pos+1] << 2;
            vv += vres[pos+2] << 1;
            vv += vres[pos+3];
            printf("%X", vv);
        }
        printf("\n");
        release_tree(root);
    }
    return 0;
}

