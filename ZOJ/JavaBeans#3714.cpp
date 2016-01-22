#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 256;
int a[MAXN] = {};

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int m, n;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        int acc = 0;
        for (int i = 0; i < m; i++) acc += a[i];
        int ans = acc;
        for (int i = 1; i < n; i++) {
            acc += (a[(i+m-1)%n] - a[i-1]);
            ans = max(ans, acc);
        }
        printf("%d\n", ans);
    }
    return 0;
}
