#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, char const *argv[])
{
    int t;
    scanf ("%d", &t);
    while (t--) {
        char buf[16];
        scanf ("%s", buf);
        int sign = 1, best = 0, m;
        if (!strcmp (buf, "Faster")) sign = -1, best = -INF;
        scanf ("%d", &m);
        while (m--) {
            int val;
            scanf ("%d", &val);
            best = max (best, val * sign);
        }
        printf("%d\n", best * sign);
    }
    return 0;
}
