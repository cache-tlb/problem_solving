class Solution {
public:
    const long long mod = 1000000000+7;
    int checkRecord(int n) {
        // 1: tail P
        // 2: tail PL
        // 3: tail PLL
        if (n == 0) return 0;
        if (n == 1) return 3;
        std::vector<long long> cache1(n+1, 0), cache2(n+1, 0), cache3(n+1, 0);
        cache1[1] = 1;
        cache2[1] = 1;
        cache3[1] = 0;
        for (int i = 2; i <= n; i++) {
            cache1[i] = (cache1[i-1] + cache2[i-1] + cache3[i-1]) % mod;
            cache2[i] = cache1[i-1];
            cache3[i] = cache2[i-1];
        }
        long long res = 0;
        for (int k = 1; k < n - 1; k++) {
            int left = k, right = (n - 1 - k);
            long long s1 = (cache1[left]+cache2[left]+cache3[left])%mod;
            long long s2 = (cache1[right]+cache2[right]+cache3[right])%mod;
            res = (res+(s1*s2)%mod) % mod;
        }
        res = (res+(cache1[n-1]+cache2[n-1]+cache3[n-1])*2+cache1[n]+cache2[n]+cache3[n])%mod;
        return res;
    }
};