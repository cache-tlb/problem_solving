class Solution {
public:
    int minCut(std::string s) {
        int n = s.length();
        if (n <= 1) return 0;
        std::vector<std::vector<int> > nexts(n);
        for (int i = 0; i < n; i++) {
            for (int len = 0; i - len >= 0 && i + len < n; len++) {
                if (s[i-len] == s[i+len]) nexts[i-len].push_back(i+len);
                else break;
            }
            for (int len = 0; i - len >= 0 && i + 1 + len < n; len++) {
                if (s[i-len] == s[i+1+len]) nexts[i-len].push_back(i+1+len);
                else break;
            }
        }
        std::vector<int> cache(n+1,n);
        cache[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int min_seg = n;
            for (auto it = nexts[i].begin(); it != nexts[i].end(); it++) {
                int next_begin = *it + 1;
                min_seg = std::min(min_seg, cache[next_begin] + 1);
                if (min_seg == 1) break;
            }
            cache[i] = min_seg;
        }
        return cache[0] - 1;
    }
};