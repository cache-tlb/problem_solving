#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 32;

int adj[MAXN][MAXN];
int N;
typedef set<int>::iterator IterType;

int process() {
    set<int> S, T;
    S.insert(0);
    for(int i = 1; i < N; i++) {
        T.insert(i);
    }
    int sum = 0;
    while(!T.empty()) {
        int minlen = INF, minpos = -1;
        for(IterType it1 = S.begin(); it1 != S.end(); it1 ++) {
            for(IterType it2 = T.begin(); it2 != T.end(); it2 ++) {
                if(adj[*it1][*it2] < minlen) {
                    minlen = adj[*it1][*it2];
                    minpos = *it2;
                }
            }
        }
        sum += minlen;
        S.insert(minpos);
        T.erase(minpos);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF) {
        if(!N) break;
        memset(adj, 0x3f, sizeof(adj));
        for(int i = 0; i < N - 1; i++) {
            int len, m;
            char c;
            cin >> c >> m;
            int u = c - 'A';
            for(int j = 0; j < m; j++) {
                cin >> c >> len;
                int v = c - 'A';
                adj[u][v] = len;
                adj[v][u] = len;
            }
        }
        printf("%d\n", process());
    }
    return 0;
}
