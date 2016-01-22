#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int parent;
    int depth;
    int cnt;
    vector<int> child;
    Node():parent(-1),cnt(0),depth(0){}
    void add_child(int c){
        child.push_back(c);
    }
    void set_parent(int p){
        parent = p;
    }
};

char buf[1024];
int N;
vector<Node> nodes;

int find_root() {
    int cur_id = N;
    while(nodes[cur_id].parent >= 0) cur_id = nodes[cur_id].parent;
    return cur_id;
}

void expand(int root, int depth) {
    Node &node = nodes[root];
    node.depth = depth;
    int n = node.child.size();
    for(int i = 0; i < n; i++){
        int cid = node.child[i];
        expand(cid, depth + 1);
    }
}

int find_lca(int uid, int vid) {
    while(nodes[uid].depth > nodes[vid].depth) uid = nodes[uid].parent;
    while(nodes[vid].depth > nodes[uid].depth) vid = nodes[vid].parent;
    while(uid != vid){
        uid = nodes[uid].parent;
        vid = nodes[vid].parent;
    }
    return uid;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF) {
        nodes.clear();
        nodes.resize(N + 1);
        for(int i = 0; i < N; i++) {
            int m, id;
            scanf("%d:(%d)", &id, &m);
            while(m--){
                int child_id;
                scanf("%d", &child_id);
                nodes[id].add_child(child_id);
                nodes[child_id].set_parent(id);
            }
        }
        int root = find_root();
        expand(root, 0);
        int nQuery;
        scanf("%d", &nQuery);
        while(nQuery--){
            int u = 0, v = 0;
            scanf("%s", buf);
            sscanf(buf, "(%d,%d)", &u, &v);
            int lca = find_lca(u, v);
            nodes[lca].cnt++;
        }
        for(int i = 1; i <= N; i++){
            int cnt = nodes[i].cnt;
            if(cnt > 0) {
                printf("%d:%d\n", i, cnt);
            }
        }
    }
    return 0;
}
