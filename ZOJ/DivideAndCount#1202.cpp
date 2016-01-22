#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139};

int nPrime = sizeof(prime)/sizeof(int);

void factorlize(int x, map<int,int> &factor) {
    int i = 0;
    while(x > 1 && i < nPrime) {
        if(x % prime[i] == 0){
            factor[prime[i]]++;
            x /= prime[i];
        }
        else {
            i++;
        }
    }
}

void desolve(int x, map<int,int> &factor) {
    for(int i = 2; i <= x; i++) {
        factorlize(i, factor);
    }
}

void print_factor(std::map<int, int> fact) {
    for(std::map<int, int>::iterator it = fact.begin(); it != fact.end(); it++) {
        printf("%d %d\n", it->first, it->second);
    }
}

int main(int argc, char const *argv[])
{
    int N;
    while(scanf("%d", &N) != EOF) {
        int sum = 0;
        map<int,int> tot_factor, div_factor, dif_num;
        for(int i = 0; i < N; i++) {
            int tmp;
            scanf("%d", &tmp);
            sum += tmp;
            dif_num[tmp]++;
            desolve(tmp, div_factor);
        }
        for(map<int,int>::iterator it = dif_num.begin(); it != dif_num.end(); it++) {
            desolve(it->second, div_factor);
        }
        desolve(sum, tot_factor);
        for(map<int,int>::iterator it = div_factor.begin(); it != div_factor.end(); it++) {
            tot_factor[it->first] -= it->second;
        }
        int ans = 1;
        for(map<int,int>::iterator it = tot_factor.begin(); it != tot_factor.end(); it++) {
            int t = it->second;
            for(int i = 0; i < t; i++) ans *= it->first;
        }
        printf("%d\n", ans);
    }
    return 0;
}
