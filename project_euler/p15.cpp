#include <iostream>
#include <cstring>
using namespace std;

long long cache[42][42];

long long c(int n, int k) {
    if (cache[n][k] >= 0) return cache[n][k];
    if (n < k) {
        cache[n][k] = 0;
        return 0;
    }
    if (k == 0 || n == 1) {
        cache[n][k] = 1;
        return 1;
    }
    cache[n][k] = c(n-1, k) + c(n-1, k-1);
    return cache[n][k];
}

int main(int argc, char const *argv[])
{
    memset(cache, -1, sizeof cache);
    cout << c(40, 20) << endl;
    return 0;
}
