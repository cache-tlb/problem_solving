class Solution {
public:
    const long long mod = 1000000000+7;
    int numDecodings(string s) {
        std::vector<long long> cache;
        cache.resize(s.length() + 1, -1);
        cache[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            long long res = 0;
            if (i == 1) {
                if (s[i-1] == '*') {
                    res = 9;
                } else if (s[i-1] == '0') {
                    res = 0;
                } else {
                    res = 1;
                }
            } else {
                if (s[i-1] == '*') {
                    res = (cache[i-1]*9)%mod;
                    if (s[i-2] == '2') {
                        res += (cache[i-2]*6)%mod;
                    } else if (s[i-2] == '1') {
                        res += (cache[i-2]*9)%mod;
                    } else if (s[i-2] == '*') {
                        res += (cache[i-2]*15)%mod;
                    }
                } else if (s[i-1] >= '0' && s[i-1] <= '6') {
                    if (s[i-1] >= '1') res = cache[i-1];
                    if (s[i-2] == '1' || s[i-2] == '2') {
                        res += cache[i-2];
                    } else if (s[i-2] == '*') {
                        res += (cache[i-2]*2)%mod;
                    }
                } else {
                    res = cache[i-1];
                    if (s[i-2] == '1' || s[i-2] == '*') {
                        res += cache[i-2];
                    }
                }
            }
            res = res % mod;
            cache[i] = res;
        }
        return cache[s.length()];
    }
};