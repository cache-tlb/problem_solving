#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                if (i == n - 1 && j == n - 1) printf("%d", 100);
                else if (i == j) printf("%d", 0);
                else printf("%d", 1);
                if(j == n - 1) printf("\n");
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
