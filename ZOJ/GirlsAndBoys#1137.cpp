#include <cstdio>
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

/* Maximal independent set */

#define MAX 1002

class HungaryMatch{
public:
    int nx, ny;
    int nMatch;
    list<int> adj[MAX];
    int mat[MAX];
    //int nNeighbor[MAX];
    bool used[MAX];

    HungaryMatch(int _nx, int _ny)
        :nx(_nx), ny(_ny),nMatch(0) {
        //memset(adj, -1, sizeof(adj));
        memset(mat, -1, sizeof(mat));
        //memset(nNeighbor, 0, sizeof(nNeighbor));
        memset(used, 0, sizeof(used));
    }

    void add_edge(int xval, int yval){
        adj[xval].push_back(yval);
    }

    bool crosspath(int k){
        // k belongs to set X
        for (list<int>::iterator it = adj[k].begin(); it != adj[k].end(); it++){
            int j = *it;  // j belongs to set Y
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

int N;

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF){
        //cout << "N:" << N << endl;
        HungaryMatch hm(N, N);
        for(int i = 0; i < N; i++) {
            int id, m, nid;
            scanf("%d: (%d)", &id, &m);
            for(int j = 0; j < m; j++){
                scanf("%d", &nid);
                hm.add_edge(id, nid);
            }
            //printf("i = %d, id = %d, m = %d\n", i, id, m);
        }
        hm.hungary();
        printf("%d\n", N - hm.nMatch/2);
    }
    return 0;
}
