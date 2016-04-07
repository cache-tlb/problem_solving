#include <cstdio>

const int MAXN = 108;
int h[MAXN][MAXN] = {};
int table[MAXN][MAXN] = {};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int m, n;

int query(int i, int j) {
    if (table[i][j] >= 0) return table[i][j];
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int ii = i + dy[k], jj = j + dx[k];
        if (ii >= 0 && ii < n && jj >= 0 && jj < m && h[ii][jj] < h[i][j]) {
            int tmp = query(ii,jj) + 1;
            if (tmp > ans) ans = tmp;
        }
    }
    table[i][j] = ans;
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &h[i][j]);
            table[i][j] = -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int res = query(i,j);
            if (res > ans) ans = res;
        }
    }
    printf("%d\n", ans + 1);
    return 0;
}
