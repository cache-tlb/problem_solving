#include <cstdio>
#include <string>

int main() {
    int n0;
    int T = 1;
    while (1) {
        scanf("%d", &n0);
        if (!n0) break;
        std::string oe;
        int q;
        int n1 = 3*n0, n2;
        if (n1 % 2) {
            oe = "odd";
            n2 = (n1+1)/2;
        }
        else {
            oe = "even";
            n2 = n1/2;
        }
        int n3 = 3*n2;
        int n4 = n3/9;
        printf("%d. %s %d\n", T++, oe.c_str(), n4);
    }
    return 0;
}
