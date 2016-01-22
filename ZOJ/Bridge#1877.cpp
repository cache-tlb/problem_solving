#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1024;
int n;
int times[MAXN];

int main(int argc, char const *argv[])
{
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++) {
            scanf("%d", &times[i]);
        }
        sort(times, times + n);
        if(n==0){
            printf("0\n"); continue;
        }
        if(n==1){
            printf("%d\n%d\n", times[0], times[0]);
            continue;
        }
        if(n==2){
            printf("%d\n%d %d\n",times[1],times[0],times[1]);
            continue;
        }
        if(n % 2 == 0){
            int sum = times[1];
            for(int i = 3; i < n; i+=2) {
                sum += min(times[i] + times[0] + times[1] + times[1], times[i] + times[0] + times[i-1] + times[0]);
            }
            printf("%d\n", sum);
            printf("%d %d\n", times[0], times[1]);
            for(int i = 3; i < n; i+=2) {
                if(times[i] + times[0] + times[1] + times[1] < times[i] + times[0] + times[i-1] + times[0]){
                    printf("%d\n", times[0]);
                    printf("%d %d\n", times[i - 1], times[i]);
                    printf("%d\n", times[1]);
                    printf("%d %d\n", times[0], times[1]);
                }
                else{
                    printf("%d\n", times[0]);
                    printf("%d %d\n", times[0], times[i - 1]);
                    printf("%d\n", times[0]);
                    printf("%d %d\n", times[0], times[i]);
                }
            }
        }
        else {
            int sum = times[1];
            sum += times[0] + times[2];
            for(int i = 4; i < n; i+=2){
                sum += min(times[i] + times[0] + times[1] + times[1], times[i] + times[0] + times[i-1] + times[0]);
            }
            printf("%d\n", sum);
            printf("%d %d\n", times[0], times[1]);
            printf("%d\n", times[0]);
            printf("%d %d\n", times[0], times[2]);
            for(int i = 4; i < n; i++) {
                if(times[i] + times[0] + times[1] + times[1] < times[i] + times[0] + times[i-1] + times[0]){
                    printf("%d\n", times[0]);
                    printf("%d %d\n", times[i - 1], times[i]);
                    printf("%d\n", times[1]);
                    printf("%d %d\n", times[0], times[1]);
                }
                else{
                    printf("%d\n", times[0]);
                    printf("%d %d\n", times[0], times[i - 1]);
                    printf("%d\n", times[0]);
                    printf("%d %d\n", times[0], times[i]);
                }
            }
        }
    }
    return 0;
}
