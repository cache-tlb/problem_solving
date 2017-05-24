class Solution {
public:
    bool dfs(int mat_i, int mat_j, int w_pos) {
        if (mat[mat_i][mat_j] == str[w_pos] && w_pos == str.length() - 1) return true;
        // if (w_pos >= str.length()) return true;
        if (mat[mat_i][mat_j] != str[w_pos]) return false;
        vis[mat_i*m+mat_j] = 1;
        if (mat_i + 1 < n && !vis[(mat_i+1)*m + mat_j]) {
            if (dfs(mat_i+1, mat_j, w_pos+1)) return true;
        }
        if (mat_i - 1 >= 0 && !vis[(mat_i-1)*m + mat_j]) {
            if (dfs(mat_i-1, mat_j, w_pos+1)) return true;
        }
        if (mat_j + 1 < m && !vis[mat_i*m+mat_j+1]) {
            if (dfs(mat_i, mat_j+1, w_pos+1)) return true;
        }
        if (mat_j - 1 >= 0 && !vis[mat_i*m+mat_j-1]) {
            if (dfs(mat_i, mat_j-1, w_pos+1)) return true;
        }
        vis[mat_i*m+mat_j] = 0;
        return false;
    }
    bool find(const string &word) {
        if (m==1 && n==1) {
            for (int i = 0; i < word.length(); i++) {
                if (word[i] != mat[0][0]) return false;
            }
            return true;
        }
        vis.resize(m*n);
        str = word;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                memset(&vis[0], 0, m*n*sizeof(int));
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        std::vector<string> ret;
        mat = board;
        n = board.size();
        if (!n) return ret;
        m = board[0].size();
        if (!m) return ret;
        std::set<string> w;
        for (int i = 0; i < words.size(); i++) {
            w.insert(words[i]);
        }
        for (std::set<string>::iterator it = w.begin(); it != w.end(); it++) {
            if (find(*it)) ret.push_back(*it);
        }
        return ret;
    }

    std::vector<std::vector<char> > mat;
    std::vector<int> vis;
    string str;
    int m,n;
};
