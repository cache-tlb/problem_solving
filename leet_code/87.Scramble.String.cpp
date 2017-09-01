class Solution {
public:
    std::string str1, str2;
    int cache_w;
    std::vector<int> cache;
    int find(int start1, int start2, int len) {
        int cache_id = start1*cache_w*cache_w + start2*cache_w + len;
        if (cache[cache_id] >= 0) return cache[cache_id];
        int res = 0;
        if (len == 1) {
            res = (str1[start1] == str2[start2]) ? 1 : 0;
        } else {
            for (int len1 = 1; len1 < len; len1++) {
                int len2 = len - len1;
                if (find(start1, start2, len1) && find(start1+len1, start2+len1, len2)) res = 1;
                else if (find(start1, start2+len2, len1) && find(start1+len1, start2, len2)) res = 1;
                if (res == 1) break;
            }
        }
        cache[cache_id] = res;
        return res;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (n != s2.length()) return false;
        str1 = s1;
        str2 = s2;
        cache_w = n + 1;
        cache.resize(cache_w*cache_w*cache_w, -1);
        return find(0, 0, n) == 1;
    }
};
