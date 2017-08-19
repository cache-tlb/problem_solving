class Solution {
public:
    std::string s, t;
    int n, m;
    std::vector<std::vector<int> > table;
    int get(int i, int j) {
        if (table[i][j] >= 0) return table[i][j];
        int res = m*n;
        if (i + 1 == m) {
            if (t[i] == s[j]) res = 1;
            else {
                int a = 0, b = 0;
                while (a < n && t[i] != s[(j+n-a)%n]) a++;
                while (b < n && t[i] != s[(j+b)%n]) b++;
                res = std::min(a, b) + 1;
            }
        } else {
            for (int k = 0; k < n; k++) {
                if (t[i] == s[(j+k)%n]) res = std::min(res, get(i+1, (j+k)%n)+k+1);
                if (t[i] == s[(j+n-k)%n]) res = std::min(res, get(i+1, (j+n-k)%n)+k+1);
            }
        }
        table[i][j] = res;
        return res;
    }
    int findRotateSteps(string ring, string key) {
        s = ring;
        t = key;
        n = ring.length();
        m = key.length();
        table.resize(m);    // table[m][n]
        for (int i = 0; i < m; i++) {
            table[i].resize(n, -1);
        }
        return get(0, 0);
    }
};