#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 5005;
const int MAXK = 1024;

int cache[MAXN][MAXK];

inline int sqr(int x){
    return x*x;
}

int len[MAXN];
int K, N;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &K, &N);
        K += 8;
        for(int i = 1; i <= N; i++) {
            scanf("%d", &len[i]);
        }
        for(int j = 1; j <= K; j++) {
            for(int i = 2*j; i <= N; i++) {
                int val = INF;
                if(i > 2*j) val = cache[i - 1][j];
                if(N - i > (K - j)*3) val = min(val, sqr(len[i] - len[i - 1]) + cache[i - 2][j - 1]);
                cache[i][j] = val;
            }
        }
        printf("%d\n", cache[N][K]);
    }
    return 0;
}
