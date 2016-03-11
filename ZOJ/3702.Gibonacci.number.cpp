#include <cstdio>
#include <cmath>

long long a[32];
long long MAXV = 1000000;

int tri(int i, long long gi, long long a1) {
    a[1] = a1;
    for (int k = 2; k <= i; k++) {
        a[k] = a[k-1] + a[k-2];
        if (a[k] > gi) return 1;
    }
    if (a[i] == gi) return 0;
    else if (a[i] > gi) return 1;
    else return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    a[0] = 1;
    while (T--) {
        long long i, gi, j;
        scanf("%lld%lld%lld", &i, &gi, &j);
        long long low = 1, high = MAXV, mid = (low + high) / 2;
        bool ok = false;
        while (low <= high) {
            // printf("mid: %d\n", mid);
            int res = tri(i, gi, mid);
            if (res > 0) {
                high = mid - 1;
            } else if (res < 0) {
                low = mid + 1;
            } else {
                // find
                ok = true;
                a[1] = mid;
                for (int k = 2; k <= j; k++) {
                    a[k] = a[k-1] + a[k-2];
                }
                printf("%lld\n", a[j]);
                break;
            }
            mid = (low + high) / 2;
        }
        if (!ok) printf("-1\n");
    }
    return 0;
}
