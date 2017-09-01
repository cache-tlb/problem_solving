class Solution {
public:
    std::vector<std::vector<int> > mat;
    std::vector<int> acc_row, aux;
    int m, n, lim, res;
    int check() {
        int sum = 0, ret = res;
        for (int i = 0; i < m; i++) {
            sum += acc_row[i];
            aux[i] = sum;
        }
        std::set<int> s;
        s.insert(0);
        for (int i = 0; i < m; i++) {
            int v = aux[i];
            auto it = s.lower_bound(v - lim);
            if (it != s.end()) {
                ret = std::max(ret, v - *it);
            }
            s.insert(v);
        }
        return ret;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        if (n == 0) return 0;
        m = matrix[0].size();
        lim = k;
        bool transpose = false;
        if (n > m) {
            std::swap(m,n);
            transpose = true;
        }
        mat.resize(n);
        res = -INT_MAX;
        for (int i = 0; i < n; i++) {
            mat[i].resize(m);
            for (int j = 0; j < m; j++) {
                mat[i][j] = transpose ? matrix[j][i] : matrix[i][j];
                res = std::min(res, mat[i][j]);
            }
        }
        acc_row.resize(m, 0);
        aux.resize(m, 0);
        for (int start_row = 0; start_row < n; start_row++) {
            memset(&acc_row[0], 0, sizeof(int)*m);
            for (int len = 0; start_row + len < n; len++) {
                for (int j = 0; j < m; j++) acc_row[j] += mat[start_row+len][j];
                res = std::max(res, check());
            }
        }
        return res;
    }
};

