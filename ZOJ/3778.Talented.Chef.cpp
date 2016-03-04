#include <cstdio>
#include <cmath>
#include <algorithm>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M, x;
        scanf("%d%d", &N, &M);
        int max_t = 0, sum = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &x);
            max_t = std::max(max_t, x);
            sum += x;
        }
        if (M >= N) {
            printf("%d\n", max_t);
            continue;
        }
        int mean_t = sum / M;
        if (mean_t * M < sum) mean_t++;
        if (mean_t <= max_t) printf("%d\n", max_t);
        else printf("%d\n", mean_t);
    }
    return 0;
}
