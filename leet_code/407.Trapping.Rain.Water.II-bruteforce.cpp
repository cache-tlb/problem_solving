class Solution {
public:
    int n, m;
    std::vector<int> val;
    std::vector<int> vis;
    std::vector<int> final_val;
    std::vector<std::pair<int,int> > remain_pos;    // (height, index)
    std::vector<int> q;
    std::vector<int> component;
    inline void try_put(int row, int col) {
        int id = row*m + col;
        if (!vis[id] && final_val[id] < 0) {
            vis[id] = 1;
            component.push_back(id);
            q.push_back(id);
        }
    }
    int solve() {
        remain_pos.resize(m*n);
        final_val.resize(m*n, -1);
        vis.resize(m*n);
        for (int i = 0; i < m*n; i++) {
            remain_pos[i] = std::make_pair<>(val[i], i);
        }
        std::sort(remain_pos.begin(), remain_pos.end(), [](const std::pair<int,int> &a, const std::pair<int,int> &b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });

        for (int k = 0; k < remain_pos.size(); k++) {
            int index = remain_pos[k].second;
            if (final_val[index] >= 0) continue;
            int cur_height = val[index];
            final_val[index] = cur_height;
            memset(&vis[0], 0, sizeof(int)*vis.size());
            int neighbor = 0;
            std::vector<int> cand;
            if (index/m - 1 >= 0 && final_val[index-m] >= 0) neighbor++;
            else cand.push_back(index-m);
            if (index/m + 1 < n && final_val[index+m] >= 0) neighbor++;
            else cand.push_back(index+m);
            if (index%m - 1 >= 0 && final_val[index-1] >= 0) neighbor++;
            else cand.push_back(index-1);
            if (index%m + 1 < m && final_val[index+1] >= 0) neighbor++;
            else cand.push_back(index+1);
            if (index/m - 1 >= 0 && index%m - 1 >= 0 && final_val[index-m-1] >= 0) neighbor++;
            else cand.push_back(index-m-1);
            if (index/m - 1 >= 0 && index%m + 1 < m && final_val[index-m+1] >= 0) neighbor++;
            else cand.push_back(index-m+1);
            if (index/m + 1 < n && index%m - 1 >= 0 && final_val[index+m-1] >= 0) neighbor++;
            else cand.push_back(index+m-1);
            if (index/m + 1 < n && index%m + 1 < m && final_val[index+m+1] >= 0) neighbor++;
            else cand.push_back(index+m+1);
            if (neighbor < 2) continue;
            for (auto i : cand) {
                if (vis[i] || final_val[i] >= 0) continue;
                q.clear();
                component.clear();
                bool is_boundary = false;
                q.push_back(i);
                vis[i] = 1;
                component.push_back(i);
                while (!q.empty()) {
                    int cur_index = q.back();
                    q.pop_back();
                    int cur_row = cur_index/m, cur_col = cur_index%m;
                    if (cur_row - 1 >= 0) {
                        try_put(cur_row - 1, cur_col);
                    } else is_boundary = true;
                    if (cur_row + 1 < n) {
                        try_put(cur_row + 1, cur_col);
                    } else is_boundary = true;
                    if (cur_col - 1 >= 0) {
                        try_put(cur_row, cur_col - 1);
                    } else is_boundary = true;
                    if (cur_col + 1 < m) {
                        try_put(cur_row, cur_col + 1);
                    } else is_boundary = true;
                    // if (is_boundary) break;
                }
                if (!is_boundary) {
                    for (auto id: component) {
                        final_val[id] = cur_height;
                    }
                    // break;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m*n; i++) {
            res += (final_val[i] - val[i]);
            // std::cout << final_val[i] << ' ';
        }
        // std::cout << std::endl;
        return res;
    }
    int trapRainWater(vector<vector<int> >& heightMap) {
        n = heightMap.size();
        if (!n) return 0;
        m = heightMap[0].size();
        val.resize(m*n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                val[i*m + j] = heightMap[i][j];
            }
        }
        return solve();
    }
};
