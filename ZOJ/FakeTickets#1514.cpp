#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10000+10;

int main(int argc, char const *argv[])
{
    int N, M;
    int ti;
    while(scanf("%d%d", &N, &M)){
        if(!N && !M) break;
        int tickets[MAXN] = {};
        for(int i = 0; i < M; i++){
            scanf("%d", &ti);
            tickets[ti]++;
        }
        int num = 0;
        for(int i = 1; i <= N; i++){
            if(tickets[i] > 1) num ++;
        }
        printf("%d\n", num);
    }
    return 0;
}
