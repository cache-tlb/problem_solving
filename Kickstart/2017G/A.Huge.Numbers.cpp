#include <iostream>
#include <cstdio>

using namespace std;

void fast_pow(long long &a, int x, long long p)
{
    int idx = 1;
    long long ret = 1;
    long long tmp = a;
    while (x >= idx)
    {
        if (x & idx)
        {
            ret = ret * tmp % p;
        }
        idx <<= 1;
        tmp = tmp * tmp % p;
    }
    a = ret;
}

int main()
{
    long long a, p;
    freopen ("A-large.in", "r", stdin);
    freopen ("A-large.out", "w", stdout);
    int n, times;
    cin >> times;
    for(int iter = 1; iter <= times; ++iter)
    {
        cin >> a >> n >> p;
        long long ans = a % p;
        for(int i = 2; i <= n; ++i)
        {
            fast_pow(ans, i, p);
            //cout << ans << endl;
        }
        cout << "Case #" << iter << ": " << ans << endl;
    }
    return 0;
}
