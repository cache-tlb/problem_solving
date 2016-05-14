#include <cstdio>
#include <algorithm>
#include <cmath>

const int MAXN = 52;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int m, n;
        scanf("%d %d", &m, &n);
        int s1 = 0, s2 = 0;
        int x;
        for (int i = 0; i < m - 1; i++) {
            scanf("%d", &x);
            s1 += x;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            s2 += x;
        }
        double avg1 = double(s1)/(m - 1), avg2 = double(s2)/n;
        int low = ceil(avg2), high = floor(avg1);
        if (low == avg2) low++;
        if (high == avg1) high--;
        printf("%d %d\n", low, high);
    }
    return 0;
}
