// minimal spanning tree
#include <cstdio>
#include <algorithm>
#include <set>

int N;
const int MAXN = 128;
int c[MAXN][MAXN] = {};

typedef struct {
    int rank;
    int p;
    int size;
} uni_elt;

class universe {
public:
    universe(int elements);
    ~universe();
    int find(int x);  
    void join(int x, int y);
    int size(int x) const { return elts[x].size; }
    int num_sets() const { return num; }

private:
    uni_elt *elts;
    int num;
};

inline universe::universe(int elements) {
    elts = new uni_elt[elements];
    num = elements;
    for (int i = 0; i < elements; i++) {
        elts[i].rank = 0;
        elts[i].size = 1;
        elts[i].p = i;
    }
}

inline universe::~universe() {
    delete [] elts;
}

inline int universe::find(int x) {
    int y = x;
    while (y != elts[y].p)
        y = elts[y].p;
    elts[x].p = y;
    return y;
}

inline void universe::join(int x, int y) {
    if (elts[x].rank > elts[y].rank) {
        elts[y].p = x;
        elts[x].size += elts[y].size;
    } else {
        elts[x].p = y;
        elts[y].size += elts[x].size;
        if (elts[x].rank == elts[y].rank)
            elts[y].rank++;
    }
    num--;
}

struct Edge {
    int i, j, v;
    Edge() : i(-1), j(-1), v(-1) {}
    Edge(int i_, int j_, int v_) : i(i_), j(j_), v(v_) {}
};

bool cmp (const Edge &a, const Edge &b) {
    return a.v < b.v;
}

Edge edges[MAXN*MAXN] = {};

int main() {
    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        int edge_count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &c[i][j]);
                if (i != j) edges[edge_count++] = Edge(i, j, c[i][j]);
            }
        }
        std::sort(edges, edges + edge_count, cmp);
        int net_edge = 0;
        int ans = 0;
        universe u(N);
        for (int i = 0; i < edge_count; i++) {
            Edge &e = edges[i];
            int i_group = u.find(e.i), j_group = u.find(e.j);
            if (i_group == j_group) continue;
            u.join(i_group, j_group);
            ans += e.v;
            net_edge++;
            if (net_edge == N - 1) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
Sample Input
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
Sample Output
28
*/