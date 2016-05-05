#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a < b) printf("NO BRAINS\n");
        else printf("MMM BRAINS\n");
    }
    return 0;
}

/*
Sample Input

3
4 5
3 3
4 3
Sample Output

NO BRAINS
MMM BRAINS
MMM BRAINS
*/