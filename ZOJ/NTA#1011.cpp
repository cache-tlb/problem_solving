#include <iostream>
#include <cstdio>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

const int MAXSIGNAL = 16;
const int MAXCHAR = 16;
const int BUFSIZE = 1024;

struct Node {
    Node *lc, *rc;
    int val;
    Node():val(-1),lc(NULL),rc(NULL){}
    Node(int _val):val(_val),lc(NULL),rc(NULL){}
    Node(char c):lc(NULL),rc(NULL){
        if(c=='*') val = -1;
        else val = c-'a';
    }
};

vector<pii> table[MAXSIGNAL][MAXCHAR];
string buffer;

int n, m, k;

void release_tree(Node *node){
    if(node->lc) release_tree(node->lc);
    if(node->rc) release_tree(node->rc);
    delete node;
}

bool dfs(Node *node, int signal_num){
    if(node->val==-1){
        return signal_num >= n - m;
    }
    int index = node->val;
    vector<pii> &rv = table[signal_num][index];
    for(int i = 0; i < (int)rv.size(); i++) {
        int l_sig = rv[i].first, r_sig = rv[i].second;
        if(dfs(node->lc, l_sig) && dfs(node->rc, r_sig)){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    while(cin >> n >> m >> k){
        if(!n && !m && !k) break;
        getchar();
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                table[i][j].clear();
                getline(cin, buffer);
                int a, b;
                istringstream iss(buffer);
                while(iss >> a >> b){
                    table[i][j].push_back(pii(a,b));
                }
            }
        }
        int level;
        if(t) printf("\n");
        printf("NTA%d:\n", ++t);
        while(cin >> level){
            if(level < 0) break;
            char c;
            cin >> c;
            Node *root = new Node(c);
            queue<Node*> q;
            q.push(root);
            int level_node = 1;
            for(int i = 0; i < level; i++){
                for(int j = 0; j < level_node; j++){
                    Node *node = q.front();
                    q.pop();
                    char c1, c2;
                    cin >> c1 >> c2;
                    Node *left = new Node(c1);
                    Node *right = new Node(c2);
                    node->lc = left;
                    node->rc = right;
                    q.push(left);
                    q.push(right);
                }
                level_node *= 2;
            }
            while(!q.empty()){
                Node *node = q.front();
                q.pop();
                node->lc = new Node;
                node->rc = new Node;
            }
            if(dfs(root, 0)) printf("Valid\n");
            else printf("Invalid\n");
            release_tree(root);
        }
    }
    return 0;
}
