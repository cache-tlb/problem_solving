class Solution {
public:
    vector<vector<int> > matrix;
    vector<vector<int> > cache;
    int m, n;
    int get(int i, int j) {
        if (cache[i][j] >= 0) return cache[i][j];
        int res = 1;
        if (i + 1 < m && matrix[i][j] < matrix[i+1][j]) {
            res = std::max(res, get(i+1,j)+1);
        }
        if (i - 1 >= 0 && matrix[i][j] < matrix[i-1][j]) {
            res = std::max(res, get(i-1,j)+1);
        }
        if (j + 1 < n && matrix[i][j] < matrix[i][j+1]) {
            res = std::max(res, get(i,j+1)+1);
        }
        if (j - 1 >= 0 && matrix[i][j] < matrix[i][j-1]) {
            res = std::max(res, get(i,j-1)+1);
        }
        cache[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        this->matrix = matrix;
        m = matrix.size();
        n = matrix[0].size();
        cache.resize(m);
        for (int i = 0; i < m; i++) cache[i].resize(n, -1);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = std::max(res, get(i,j));
            }
        }
        return res;
    }
};