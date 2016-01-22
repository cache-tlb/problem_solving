#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int T, t1, t2;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &t1, &t2);
        int tot = 0;
        for(int k = t1; k <= t2; k++) {
            int k1 = k % 100, k2 = k % 1000;
            int s1 = (int)sqrt((float)k1), s2 = (int)sqrt((float)k2);
            if(s1 * s1 == k1 && s1 > 0) tot++;
            else if(s2 *s2 == k2 && s2 <= 12 && s2 > 0) tot++;
        }
        printf("%d\n", tot);
    }
    return 0;
}
