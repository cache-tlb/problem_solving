#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        const int MAXN = 60;
        int h[MAXN];
        for (int i = 0; i < N; i++) {
            scanf("%d", &h[i]);
        }
        int cnt = 0;
        for (int i = 1; i < N - 1; i++) {
            if (h[i] > h[i-1] && h[i] > h[i+1]) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
