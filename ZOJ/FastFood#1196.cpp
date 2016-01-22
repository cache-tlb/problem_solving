#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

/* simple dynamic programing */

const int INF = 0x3f3f3f3f;
const int MAXN = 256;
const int MAXK = 32;
int cache[MAXK][MAXN];
int position[MAXN];

int search(int k, int n) {
    if(cache[k][n] >= 0) return cache[k][n];
    if(n==0) return 0;
    if(k==0) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += position[n] - position[i];
        }
        cache[k][n] = sum;
        return sum;
    }
    else {
        int min_cost = INF;
        for(int nn = n - 1; nn >= 0; nn--){
            int prev_cost = search(k - 1, nn);
            for(int i = nn + 1; i <= n - 1; i++) {
                prev_cost += min(position[i] - position[nn], position[n] - position[i]);
            }
            if(prev_cost < min_cost) min_cost = prev_cost;
        }
        cache[k][n] = min_cost;
        return min_cost;
    }
}

int N, K;

int main(int argc, char const *argv[])
{
    int t = 0;
    while(scanf("%d%d", &N, &K) != EOF) {
        if(!N && !K) break;
        for(int i = 0; i < N; i++){
            scanf("%d", &position[i]);
        }
        memset(cache, -1, sizeof(cache));
        int ans = INF;
        for(int i = K - 1; i < N; i++){
            int sum = 0;
            for(int j = i + 1; j < N; j++){
                sum += position[j] - position[i];
            }
            sum += search(K-1,i);
            if(sum < ans) ans = sum;
        }
        /*for(int i = 0; i < K; i++){
            for(int j = 0; j < N; j++){
                printf("%d\t", cache[i][j]);
            }
            printf("\n");
        }*/
        printf("Chain %d\n", ++t);
        printf("Total distance sum = %d\n\n", ans);
    }
    return 0;
}
