#include <cstdio>
#include <vector>
#include <map>

const int MOD = 1000000007;
int n;
// ai <= 100000
// n <= 1000000
std::vector<int> a;
std::vector<int> f;
std::map<int,int> f_pos;
int solve() {
    long long res = 0;
    std::vector<long long> cache1, cache2;
    cache1.resize(n+1, 0);
    cache2.resize(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (a[i-1] == 1) cache1[i] = cache1[i-1] + 1;
        else cache1[i] = cache1[i-1];
    }
    res = cache1[n];
    for (int k = 1; k < f.size(); k++) {
        cache2[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i-1] == f[k]) cache2[i] = (cache2[i-1] + cache1[i-1]) % MOD;
            else cache2[i] = cache2[i-1];
        }
        res = (res + cache2[n]) % MOD;
        cache1.swap(cache2);
    }
    return (int)res;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    f.resize(26);
    f[0] = f[1] = 1;
    for (int i = 2; i < f.size(); i++) {
        f[i] = f[i-1] + f[i-2];
        f_pos[f[i]] = i;
        // printf("%d\n", f[i]);
    }
    scanf("%d", &n);
    a.reserve(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1 || f_pos.count(x) > 0) {
            a.push_back(x);
        }
    }
    n = a.size();
    int res = solve();
    printf("%d\n", res);
    return 0;
}
