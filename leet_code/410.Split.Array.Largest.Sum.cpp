class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        std::vector<long long> s_vec(n+1);
        long long s = 0;
        for (int i = 0; i <= n; i++) {
            s_vec[i] = s;
            s += nums[i];
        }
        std::vector<long long> cache1(n, 0), cache2(n, 0);
        for (int i = 0; i < n; i++) {
            cache1[i] = s_vec[i+1];
        }
        for (int j = 2; j <= m; j++) {
            for (int i = 0; i < n; i++) {
                long long x = s;
                for (int k = i; k >= 1; k--) {
                    // max(a[m-1][k-1], s[k...i])
                    x = std::min(x, std::max(cache1[k-1], s_vec[i+1] - s_vec[k]));
                }
                cache2[i] = x;
            }
            cache1.swap(cache2);
        }
        // std::cout << cache1[n-1];
        return (int)cache1[n-1];
    }
};