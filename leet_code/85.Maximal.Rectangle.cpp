class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size();
        if (!m) return 0;
        std::vector<std::vector<int> > ones_on_left(n);
        for (int i = 0; i < n; i++) {
            ones_on_left[i].resize(m, 0);
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') count++;
                else  count = 0;
                ones_on_left[i][j] = count;
            }
        }
        std::vector<std::pair<int,int> > stack;
        stack.reserve(n);
        int res = 0;
        for (int j = 0; j < m; j++) {
            stack.clear();
            for (int i = 0; i < n; i++) {
                int pos = i;
                int hist = ones_on_left[i][j];
                while (!stack.empty() && hist < stack.back().first) {
                    std::pair<int,int> val_pos = stack.back();
                    stack.pop_back();
                    pos = val_pos.second;
                    res = std::max(res, val_pos.first*(i - pos));
                }
                stack.push_back(std::make_pair<>(ones_on_left[i][j], pos));
            }
            while (!stack.empty()) {
                std::pair<int,int> val_pos = stack.back();
                stack.pop_back();
                res = std::max(res, val_pos.first*(n - val_pos.second));
            }
        }
        return res;
    }
};