class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = std::min<int>(k, prices.size()/2);
        if (k <= 0 || n < 2) return 0;
        std::vector<int> cache1(n, 0), cache2(n, 0);
        for (int i = 0; i < k; i++) {
            int max_profit_last = -prices[0];
            for (int j = 1; j < n; j++) {
                max_profit_last = std::max(max_profit_last, cache1[j-1] - prices[j-1]);
                cache2[j] = std::max(cache2[j-1], prices[j] + max_profit_last);
            }
            cache2.swap(cache1);
        }
        return cache1[n-1];
    }
};
