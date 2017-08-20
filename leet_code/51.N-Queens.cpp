class Solution {
public:
    int size;
    std::vector<std::string> board;
    std::vector<std::vector<std::string> > res;
    void try_put(int row, int col) {
        int i = row, j = col;
        for (i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return;
        }
        for (i = row - 1, j = col + 1; i >= 0 && j < size; i--, j++) {
            if (board[i][j] == 'Q') return;
        }
        for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return;
        }
        board[row][col] = 'Q';
        if (row + 1== size) {
            res.push_back(board);
        }
        else for (int k = 0; k < size; k++) {
            try_put(row+1, k);
        }
        board[row][col] = '.';
    }
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n);
        size = n;
        for (int i = 0; i < n; i++) {
            board[i].resize(n, '.');
        }
        for (int i = 0; i < n; i++) {
            try_put(0, i);
        }
        return res;
    }
};
