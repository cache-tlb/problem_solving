class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        std::vector<int> cache1(n, 0), cache2(n, 0);
        int tmp = -prices[0];
        for (int i = 1; i < n; i++) {
            tmp = std::max(tmp, -prices[i-1]);
            cache1[i] = std::max(cache1[i-1], prices[i]+tmp);
        }
        tmp = -prices[0];
        for (int i = 1; i < n; i++) {
            tmp = std::max(tmp, cache1[i-1] - prices[i-1]);
            cache2[i] = std::max(cache2[i-1], prices[i]+tmp);
        }
        return cache2[n-1];
    }
};