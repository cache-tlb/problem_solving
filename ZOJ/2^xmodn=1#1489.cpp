#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    while(scanf("%d", &N) != EOF){
        if(N < 3 || !(N % 2)) {
            printf("2^? mod %d = 1\n", N);
        }
        else {
            int p = 2, x = 1;
            while(p % N != 1) {
                p = (p*2) % N;
                x ++;
            }
            printf("2^%d mod %d = 1\n", x, N);
        }
    }
    return 0;
}
