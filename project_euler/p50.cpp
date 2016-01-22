#include <cstdio>
#include <iostream>
using namespace std;

const int limit = 1000000;
const int MAX = limit + 10;

int isnonprime[MAX]={};  //0 for prime
long long primes[MAX]={};
int nprime = 0;
long long s[MAX] = {};
void ini()
{
    int d = 2;
    do{
        int k = d;
        if(isnonprime[k]==0){
            k += d;
            while(k <= MAX){
                isnonprime[k] = 1;
                k += d;
            }
        }
        d++;
    }while(d*d<=MAX);
    isnonprime[0] = isnonprime[1] = 1;
    for (long long i = 0; i < MAX; i++) {
        if (!isnonprime[i]) primes[nprime++] = i;
    }
    long long sum = 0;
    for (int i = 0; i < nprime; i++) {
        sum += primes[i];
        s[i] = sum;
    }
    cout << nprime << endl;
    /*for(int i = 0; i < nprime; i++){
       cout << s[i] << ' ';
    }*/
}

int main(int argc, char const *argv[])
{
    ini();
    int ans = 10;
    int p = -1;
    for (int i = 0; i < nprime; i++) {
        for (int j = i + ans; j < nprime; j++) {
            if (s[j] - s[i] >= limit) break;
            if (!isnonprime[s[j] - s[i]]) ans = (j - i > ans) ? (p = s[j]-s[i], j - i) : (ans);
        }
    }
    cout << ans << ' ' << p << endl;
    return 0;
}
