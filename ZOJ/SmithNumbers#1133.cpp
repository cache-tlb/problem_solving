#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXPRIME = 10005;

int prime[MAXPRIME] = {};
int isprime[MAXPRIME] = {};
int nprime = 0;

int digit_sum(int x) {
    int sum = 0;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

bool is_prime_f(int x){
    if(x < MAXPRIME) return isprime[x];
    for(int i = 0; i < nprime && prime[i]*prime[i] <= x; i++) {
        if(x % prime[i] == 0) return false;
    }
    return true;
}

int prime_sum(int x){
    int sum = 0;
    if(is_prime_f(x)) return -1;
    for(int i = 0; i < nprime; i++) {
        if(is_prime_f(x) || x <= 1){
            break;
        }
        while(x % prime[i] == 0){
            sum += digit_sum(prime[i]);
            x /= prime[i];
        }
    }
    if(x > 1) sum += digit_sum(x);
    return sum;
}

int process(int n) {
    int ans = n + 1;
    while(true){
        int s = digit_sum(ans);
        int ps = prime_sum(ans);
        if(s == ps) break;
        ans++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    memset(isprime, -1, sizeof(isprime));
    for(int i = 2; i < MAXPRIME; i++) {
        if(!isprime[i]) continue;
        int k = i * 2;
        while(k < MAXPRIME) {
            isprime[k] = 0;
            k += i;
        }
    }
    for(int i = 2; i < MAXPRIME; i++) {
        if(isprime[i]){
            prime[nprime++] = i;
        }
    }
    /*for(int i = 0; i < 20; i++) {
        cout << prime[i] << endl;
    }*/
    int n;
    while(scanf("%d", &n)) {
        if(!n) break;
        printf("%d\n", process(n));
    }
    return 0;
}
