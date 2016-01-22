#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 32;

int N;
int is_prime[100] = {};
int vis[MAXN] = {};
int a[MAXN] = {};
void init() {
    int tmp[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(int i = 0; i < 25; i++) {
        is_prime[tmp[i]] = 1;
    }
}
int depth;

void rec() {
    if(depth == N + 1 && is_prime[a[N] + a[1]]){
        printf("%d", a[1]);
        for(int i = 2; i <= N; i++){
            printf(" %d", a[i]);
        }
        printf("\n");
        return;
    }
    int start = (a[depth - 1] % 2) ? 2 : 3;
    for(int k = start; k <= N; k+=2) {
        if(vis[k]) continue;
        if(!is_prime[a[depth - 1] + k]) continue;
        a[depth] = k;
        vis[k] = 1;
        depth ++;
        rec();
        depth--;
        vis[k] = 0;
    }
}

void process() {
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    a[1] = 1;
    depth = 2;
    rec();
}

int main(int argc, char const *argv[])
{
    init();
    int t = 0;
    while(scanf("%d", &N) != EOF) {
        printf("Case %d:\n", ++t);
        if(N % 2 == 0) process();
        printf("\n");
    }
    return 0;
}
