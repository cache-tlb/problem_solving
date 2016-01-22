#include <cstdio>
#include <vector>
using namespace std;

struct Edge {
    int v, len;
    Edge(){}
    Edge(int _v, int _len): v(_v), len(_len){}
};

const int MAXN = 512;
const int MAXK = 1024;
vector<Edge> adj[MAXN];

int N, E;
int S[MAXN];

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &N, &E);
        for(int i = 0; i < N; i++) {
            adj[i].clear();
            S[i] = 0;
        }
        for(int i = 0; i < E; i++) {
            int u, v, k;
            scanf("%d%d%d", &u, &v, &k);
            adj[u].push_back(Edge(v, k));
            adj[v].push_back(Edge(u, k));
        }
        S[0] = 1;
        int cnt = 1, sum = 0;
        while(cnt < N) {
            int minlen = MAXK, minpos = -1;
            for(int u = 0; u < N; u++) {
                if(!S[u]) continue;
                for(int j = 0; j < adj[u].size(); j++) {
                    int len = adj[u][j].len, v = adj[u][j].v;
                    if(S[v]) continue;
                    if(len < minlen) {
                        minlen = len;
                        minpos = v;
                    }
                }
            }
            cnt++;
            sum += minlen;
            S[minpos] = 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}
