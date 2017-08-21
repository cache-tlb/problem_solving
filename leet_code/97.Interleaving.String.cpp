class Solution {
public:
    std::string str1, str2, str3;
    std::vector<int> cache;
    int rows, cols;
    int find(int idx1, int idx2) {
        int cache_id = idx1*cols + idx2;
        if (cache[cache_id] >= 0) return cache[cache_id];
        int res = 0;
        if (idx1 == str1.length() && idx2 == str2.length()) {
            res = 1;
        } else {
            if (idx1 < str1.length() && str1[idx1] == str3[idx1+idx2])
                res = find(idx1+1, idx2);
            if (!res && idx2 < str2.length() && str2[idx2] == str3[idx1+idx2])
                res = find(idx1, idx2+1);
        }
        cache[cache_id] = res;
        return res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        str1 = s1;
        str2 = s2;
        str3 = s3;
        rows = s1.length() + 1;
        cols = s2.length() + 1;
        cache.resize(rows*cols, -1);
        return find(0, 0) == 1;
    }
};