class Solution {
public:
    // 1e9 + 7.
    int kInversePairs(int n, int k) {
        const int mod = 1000000000+7;
        if (k > (n-1)*n/2) return 0;
        std::vector<int> cache1(k+1, 0), cache2(k+1, 0);
        cache1[0] = 1;
        cache1[1] = 1;
        for (int i = 3; i <= n; i++) {
            int s = 0;
            for (int j = 0; j <= i - 1 && j <= k; j++) {
                s = (s + cache1[j]) % mod;
                cache2[j] = s;
            }
            for (int j = i; j <= (i-1)*(i-2)/2 && j <= k; j++) {
                s = (s + cache1[j] - cache1[j-i]) % mod;
                if (s < 0) s += mod;
                cache2[j] = s;
            }
            for (int j = std::max((i-1)*(i-2)/2 + 1, i); j <= k; j++) {
                s = (s - cache1[j-i]) % mod;
                if (s < 0) s += mod;
                cache2[j] = s;
            }
            cache1.swap(cache2);
        }
        return cache1[k];
    }
};