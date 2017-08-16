class Solution {
public:
    std::vector<std::vector<int> > cache;
    std::vector<std::vector<int> > valid;
    vector<vector<int> > mat;
    int m, n;
    int get(int i, int j) {
        if (valid[i][j]) return cache[i][j];
        int tmp = 0;
        if (i + 1 < n && j + 1 < m) {
            int tmp1 = std::max(1, get(i+1,j)-mat[i][j]);
            int tmp2 = std::max(1, get(i,j+1)-mat[i][j]);
            tmp = std::min(tmp1, tmp2);
        } else if (i + 1 < n && j + 1 >= m) {
            tmp = std::max(1, get(i+1,j)-mat[i][j]);
        } else if (i + 1 >= n && j + 1 < m) {
            tmp = std::max(1, get(i,j+1)-mat[i][j]);
        } else {
            tmp = std::max(1, -mat[i][j] + 1);
        }
        cache[i][j] = tmp;
        valid[i][j] = 1;
        return cache[i][j];
    }
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        mat = dungeon;
        n = dungeon.size();
        m = dungeon[0].size();
        cache.resize(n);
        valid.resize(n);
        for (int i = 0; i < n; i++) {
            cache[i].resize(m, -1);
            valid[i].resize(m, 0);
        }
        return get(0,0);
    }
};