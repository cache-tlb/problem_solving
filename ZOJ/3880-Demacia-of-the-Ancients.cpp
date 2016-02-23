#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int cnt = 0;
        while (n--) {
            int x;
            scanf("%d", &x);
            if (x > 6000) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
