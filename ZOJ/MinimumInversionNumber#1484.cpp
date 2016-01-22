#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int N;
int a[MAXN];

int process() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(a[j] < a[i]) cnt++;
        }
    }
    int acc = cnt, minv = cnt;
    for(int i = 0; i < N; i++) {
        acc += (N - a[i] - 1) - a[i];
        if(acc < minv) minv = acc;
    }
    return minv;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", process());
    }
    return 0;
}
