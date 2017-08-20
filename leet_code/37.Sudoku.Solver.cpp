class Solution {
public:
    vector<vector<char> > board;
    std::vector<int> rows, cols;
    int n_blank;
    bool solved;
    bool check(int i, int j, char c) {
        int ii = i/3, jj = j/3;
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c) return false;
            if (board[k][j] == c) return false;
            if (board[ii*3+k/3][jj*3+k%3] == c) return false;
        }
        return true;
    }
    void solve(int blank_id) {
        if (blank_id >= n_blank) {
            solved = true;
            return;
        }
        for (int i = 0; i < 9; i++) {
            int row = rows[blank_id], col = cols[blank_id];
            if (check(row, col, '1'+i)) {
                board[row][col] = '1'+i;
                solve(blank_id + 1);
                if (solved) return;
                board[row][col] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        this->board = board;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        n_blank = rows.size();
        solved = false;
        solve(0);
        board = this->board;
    }
};