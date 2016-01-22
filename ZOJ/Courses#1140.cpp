#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 512;

class HungaryMatch{
public:
    int nx, ny;
    int nMatch;
    int adj[MAX][MAX];
    int mat[MAX];
    int nNeighbor[MAX];
    bool used[MAX];

    HungaryMatch(int _nx, int _ny)
        :nx(_nx), ny(_ny),nMatch(0) {
        memset(adj, -1, sizeof(adj));
        memset(mat, -1, sizeof(mat));
        memset(nNeighbor, 0, sizeof(nNeighbor));
        memset(used, 0, sizeof(used));
    }

    void add_edge(int xval, int yval){
        adj[xval][nNeighbor[xval]++] = yval;
    }

    bool crosspath(int k){
        // k belongs to set X
        for (int i = 0; i < nNeighbor[k]; i++){
            int j = adj[k][i];  // j belongs to set Y
            if (!used[j]) {
                used[j] = true;
                if (mat[j] == -1 || crosspath(mat[j])) {
                    mat[j] = k;
                    return true;
                }
            }
        }
        return false;
    }

    void hungary() {
        for (int i = 0; i < nx; i++) {
            if (crosspath(i)) nMatch++;
            memset(used,0,sizeof(used));
        }
    }

};

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int P, N;
        scanf("%d%d", &P, &N);
        HungaryMatch hm(P, N);
        for(int i = 0; i < P; i++){
            int m;
            scanf("%d", &m);
            while(m--){
                int id;
                scanf("%d", &id);
                hm.add_edge(i, id - 1);
            }
        }
        hm.hungary();
        if(hm.nMatch == P) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
