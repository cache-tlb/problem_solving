#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 32;

int num[MAXN] = {};
int N;

void process() {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += num[i];
    }
    if(sum % 2){
        printf("No equal partitioning.\n");
        return;
    }
    int s1 = num[0], s2 = num[N-1];
    int p1 = 0, p2 = N-1;
    while(s1 < sum/2){
        p1 ++;
        s1 += num[p1];
    }
    s2 = sum - s1;
    if(s1 == s2){
        printf("Sam stops at position %d and Ella stops at position %d.\n", p1+1, p1+2);
    }
    else{
        printf("No equal partitioning.\n");
    }
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N)){
        if(!N) break;
        for(int i = 0; i < N; i++){
            scanf("%d", &num[i]);
        }
        process();
    }
    return 0;
}
