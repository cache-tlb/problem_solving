#include <cstdio>
using namespace std;

const int MAXN = 1000000+2;
int N = 1000000;
bool hasGen[MAXN] = {};

int calc_d(int x){
    int sum = x;
    while(x){
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    for(int i = 1; i <= N; i++){
        hasGen[i] = false;
    }
    int cur = 1;
    while(cur <= N){
        if(hasGen[cur]){
            cur++;
            continue;
        }
        int tmp = calc_d(cur);
        while(tmp <= N){
            if(hasGen[tmp]) break;
            hasGen[tmp] = true;
            tmp = calc_d(tmp);
        }
        cur++;
    }
    for(int i = 1; i <= N; i++){
        if(!hasGen[i]) printf("%d\n", i);
    }
    return 0;
}
