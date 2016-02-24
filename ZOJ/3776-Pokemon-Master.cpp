#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, x;
        int s1 = 0, s2 = 0;
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            scanf("%d", &x);
            s1 += x;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            s2 += x;
        }
        if (s1 > s2) printf("Calem\n");
        else if (s1 < s2) printf("Serena\n");
        else printf("Draw\n");
    }
    return 0;
}
