class Solution {
public:
    struct Item {
        int w, h;
    };
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (!n) return 0;
        std::vector<Item> rects(n);
        for (int i = 0; i < n; i++) {
            rects[i].w = envelopes[i].first;
            rects[i].h = envelopes[i].second;
        }
        std::sort(rects.begin(), rects.end(), [](const Item &a, const Item &b){
            return (a.w < b.w) || (a.w == b.w && a.h < b.h);
        });
        std::vector<int> cache(n, 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (rects[i].h > rects[j].h && rects[i].w > rects[j].w) {
                    x = std::max(1 + cache[j], x);
                }
            }
            cache[i] = x;
            res = std::max(res, x);
        }
        return res;
    }
};