#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;

struct Item {
    int d, i;
    Item(int dd, int ii) : d(dd), i(ii) {}
};

struct cmp {
    bool operator () (const Item &a, const Item &b) {
        return a.d < b.d || (a.d == b.d && a.i < b.i);
    }
};

int N, M, Q;
std::vector<std::vector<int> > dists;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    freopen("input.txt", "r", stdin);
    int x, y, r;
    scanf("%d%d", &N, &M);
    dists.resize(N);
    for (int i = 0; i < N; i++) {
        dists[i].resize(N, -1);
        dists[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &x, &y, &r);
        x--; y--;
        dists[x][y] = r;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dists[i][k] < 0 || dists[k][j] < 0) continue;
                int d = dists[i][k] + dists[k][j];
                if (dists[i][j] < 0 || dists[i][j] > d) {
                    dists[i][j] = d;
                }
            }
        }
    }
    scanf("%d", &Q);
    std::vector<std::pair<int,int> > Qs(Q);
    std::map<std::pair<int,int>,int> ans;
    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &x, &y);
        x--; y--;
        printf("%d\n", dists[x][y]);
    }
    return 0;
}
