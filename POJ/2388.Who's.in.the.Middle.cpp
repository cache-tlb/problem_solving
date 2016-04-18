#include <cstdio>
#include <algorithm>

const int MAXN = 10000;
int a[MAXN] = {};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    printf("%d\n", a[n/2]);
    return 0;
}
