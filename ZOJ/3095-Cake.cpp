# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstdlib>
# include <cstring>

using namespace std;

const int MAXN = 810;
int cache[MAXN][MAXN];

struct cake {
    int a, b;
};

bool cmp (const cake &c1, const cake &c2) {
    return (c2.b < c1.b) || (c2.b == c1.b && c2.a < c1.a);
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cake val[MAXN];
        for (int i = 1; i <= n; i++) {
            cin >> val[i].a >> val[i].b;
        }
        std::sort(val + 1, val + n + 1, cmp);
        val[0].a = 0;
        for (int i = 0; i <= n; i++) {
            memset(cache[i], 0, n);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i/2; j++) {
                cache[i][j] = std::max(cache[i-1][j], cache[i-1][j-1] + val[i].a);
            }
        }
        printf("%d\n", cache[n][n/2]);
    }
    return 0;
}