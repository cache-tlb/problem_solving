class Solution {
public:
    std::vector<std::vector<int> > table;
    string s, t;
    int n, m;
    int get(int i, int j) {
        if (table[i][j] >= 0) return table[i][j];
        int res = 0;
        if (i == m && j == n) {
            res = 0;
        } else if (i == m && j < n) {
            res = n - j;
        } else if (i < m && j == n) {
            res = m - i;
        } else {
            if (s[i] == t[j]) res = get(i+1,j+1);
            else {
                res = std::min(get(i+1,j)+1, get(i,j+1)+1);
                res = std::min(res, get(i+1,j+1)+1);
            }
        }
        table[i][j] = res;
        return res;
    }
    int minDistance(string word1, string word2) {
        m = word1.size(); 
        n = word2.size();
        s = word1;
        t = word2;
        table.resize(m + 1);
        for (int i = 0; i <= m; i++) table[i].resize(n + 1, -1);
        return get(0, 0);
    }
};