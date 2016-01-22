#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 512;
int N;

long long table[MAXN][MAXN];
int first_step[MAXN];


long long search(int n, int k) {
    if(table[n][k] >= 0) return table[n][k];
    if(n==k){
        table[n][k] = 1;
        return 1;
    }
    long long sum = 0, rem = n - k;
    int start = first_step[rem];
    for(int i = start; i <= rem && i < k; i++) {
        sum += search(rem, i);
    }
    table[n][k] = sum;
    return sum;
}

int main(int argc, char const *argv[])
{
    int tmp = 1, pos = 1;
    first_step[0] = 0;
    while(pos < MAXN) {
        for(int i = 0; i < tmp && pos < MAXN; i++){
            first_step[pos++] = tmp;
        }
        tmp++;
    }
    memset(table, -1, sizeof(table));
    while(scanf("%d", &N) != EOF) {
        if(!N) break;
        long long sum = 0;
        int start = first_step[N];
        for(int i = start; i < N; i++) {
            sum += search(N, i);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
