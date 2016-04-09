#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 128;
int a[MAXN][MAXN] = {};
int table[MAXN][MAXN] = {};

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(table, 0, sizeof (table));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            int x = std::max(table[i-1][j], table[i-1][j-1]);
            table[i][j] = a[i][j] + x;
        }
    }
    int ans = -1;
    for (int i = 1; i <= N; i++) {
        ans = std::max(ans, table[N][i]);
    }
    printf("%d\n", ans);
    return 0;
}
