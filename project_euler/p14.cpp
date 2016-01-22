#include <cstdio>
#include <map>
using namespace std;

int n = 1000000;

std::map<long long, int> cache;

int search(long long x) {
    if (cache.count(x) > 0) return cache[x];
    long long next = (x%2==1) ? x*3+1 : x/2;
    long long ret = search(next) + 1;
    cache[x] = ret;
    return ret;

}

int main(int argc, char const *argv[])
{
    int ans = 0;
    cache[1] = 1;
    long pos = -1;
    for (long long i = 1; i < n; i++) ans = ans < search(i) ? (pos = i, search(i)) : ans;//, printf("%lld %d\n", i, cache[i]);

    printf("%d\n", pos);
    return 0;
}
