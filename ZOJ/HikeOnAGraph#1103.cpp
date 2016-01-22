#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int pa, pb, pc;
    int depth;
    Node(){}
    Node(int a, int b, int c, int d):pa(a),pb(b),pc(c),depth(d){}
};

const int MAXN = 64;
int N;
int p1, p2, p3;
char color[MAXN][MAXN];
int visit[MAXN][MAXN][MAXN];
int ans;

inline void try_insert(queue<Node> &q, int a, int b, int c, int d) {
    if(visit[a][b][c]) return;
    else{
        q.push(Node(a, b, c, d));
        visit[a][b][c] = 1;
    }
}

void bfs() {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                visit[i][j][k] = 0;
            }
        }
    }
    queue<Node> q;
    try_insert(q, p1-1, p2-1, p3-1, 0);
    while(!q.empty()) {
        Node &node = q.front();
        int a = node.pa, b = node.pb, c = node.pc, d = node.depth;
        if(a==b && a==c) {
            ans = d;
            return;
        }
        q.pop();
        // move a
        for(int i = 0; i < N; i++) {
            if(color[a][i] == color[b][c]) try_insert(q, i, b, c, d + 1);
            if(color[b][i] == color[c][a]) try_insert(q, a, i, c, d + 1);
            if(color[c][i] == color[a][b]) try_insert(q, a, b, i, d + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    while(cin >> N){
        if(!N) break;
        cin >> p1 >> p2 >> p3;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> color[i][j];
            }
        }
        ans = -1;
        bfs();
        if(ans < 0) {
            printf("impossible\n");
        }
        else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
