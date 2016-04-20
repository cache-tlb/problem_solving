// longest common sub-sequnce

#include <cstdio>
#include <algorithm>
#include <cstring>

int N;
const int MAXN = 5006;
char str[MAXN] = {};
char rts[MAXN] = {};
int cache[2][MAXN] = {};
int main() {
    scanf("%d", &N);
    scanf("%s", str);
    for (int i = 0; i < N; i++) {
        rts[i] = str[N - 1 - i];
    }
    rts[N] = 0;
    memset(cache, 0, sizeof(cache));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x1 = cache[0][j - 1] + (str[i - 1] == rts[j - 1] ? 1 : 0);
            int x2 = std::max(cache[0][j], cache[1][j - 1]);
            cache[1][j] = std::max(x1, x2);
        }
        for (int j = 0; j <= N; j++) {
            cache[0][j] = cache[1][j];
            cache[1][j] = 0;
        }
    }
    printf("%d\n", N - cache[0][N]);
    return 0;
}

/*
5
Ab3bd

2
*/