#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/* to some extent dfs*/

const int MAXN = 128;
int city[MAXN][MAXN];
int is_set[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, K;

inline int my_max(int a, int b) {
    return a > b ? a : b;
}

inline int my_min(int a, int b) {
    return a < b ? a : b;
}

inline int my_abs(int x) {
    return x > 0 ? x : -x;
}

int search(int h, int w) {
    if(is_set[h][w] >= 0) return is_set[h][w];
    int num = city[h][w];
    int next = 0;
    for(int kk = 0; kk < 4; kk++){
        for(int len = 1; len <= K; len++){
            int i = h + len*dx[kk], j = w + len*dy[kk];
            if(i < 0 || i >= N || j < 0 || j >= N) continue;
            if(city[i][j] <= num) continue;
            int tmp = search(i, j);
            if(tmp > next) next = tmp;
        }
    }
    is_set[h][w] = num + next;
    return num + next;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d%d", &N, &K) != EOF) {
        if(N < 0 && K < 0) break;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%d", &city[i][j]);
            }
        }
        memset(is_set, -1, sizeof(is_set));
        printf("%d\n", search(0,0));
    }
    return 0;
}
