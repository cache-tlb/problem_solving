class Solution {
public:
    std::vector<std::vector<int> > board;
    int ans;
    int size;
    void try_put(int row, int col) {
        int i = row, j = col;
        for (i = 0; i < row; i++) {
            if (board[i][col]) return;
        }
        for (i = row - 1, j = col + 1; i >= 0 && j < size; i--, j++) {
            if (board[i][j]) return;
        }
        for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j]) return;
        }
        if (row + 1== size) {
            ans++;
            return;
        }
        board[row][col] = 1;
        for (int k = 0; k < size; k++) {
            try_put(row+1, k);
        }
        board[row][col] = 0;
    }
    int totalNQueens(int n) {
        board.resize(n);
        size = n;
        for (int i = 0; i < n; i++) {
            board[i].resize(n, 0);
        }
        ans = 0;
        for (int i = 0; i < n; i++) {
            try_put(0,i);
        }
        return ans;
    }
};