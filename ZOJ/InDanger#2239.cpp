#include <cstdio>
#include <cstring>
using namespace std;

int f(int n) {
    if (n == 1) return 1;
    if (n % 2) return 2 * f((n - 1) / 2) + 1;
    else return 2 * f(n / 2) - 1;
}

int getN(char *buf) {
    int e = buf[3] - '0';
    int xy = 10 * (buf[0] - '0') + (buf[1] - '0');
    while(e--) xy *= 10;
    return xy;
}

int main(int argc, char const *argv[])
{
    char buf[8];
    while(scanf("%s", buf) != EOF) {
        if (!strcmp(buf, "00e0")) break;
        int n = getN(buf);
        int m = 2;
        printf("%d\n", f(n));
    }
    return 0;
}
