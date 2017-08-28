#include <cstdio>
#include <vector>

const int MAXN = 729+5;
const int MAXM = 324+5;

struct Node {
    int up, down, left, right, row, col;
    Node() {}
};

bool solved = false;
int n, m;
int table[MAXN][MAXM];
int row_head_id[MAXN];
int col_ones[MAXM];
std::vector<Node> nodes;
std::vector<int> pushed_res;
int board[9][9];

void insert(int rid, int cid) {
    int nid = nodes.size();
    Node node;
    int up_id = nodes[cid].up;
    node.up = up_id;
    nodes[cid].up = nid;
    node.down = cid;
    nodes[up_id].down = nid;
    if (row_head_id[rid] < 0) {
        node.left = node.right = nid;
        row_head_id[rid] = nid;
    } else {
        int left_id = nodes[row_head_id[rid]].left;
        node.left = left_id;
        nodes[row_head_id[rid]].left = nid;
        node.right = row_head_id[rid];
        nodes[left_id].right = nid;
    }
    node.row = rid;
    node.col = cid;
    nodes.push_back(node);
    col_ones[cid]++;
}

// remove all rows that contain 1 in col `col'
void remove(int col) {
    nodes[nodes[col].right].left = nodes[col].left;
    nodes[nodes[col].left].right = nodes[col].right;
    for (int i = nodes[col].down; i != col; i = nodes[i].down) {
        for (int j = nodes[i].right; j != i; j = nodes[j].right) {
            nodes[nodes[j].down].up = nodes[j].up;
            nodes[nodes[j].up].down = nodes[j].down;
            col_ones[nodes[j].col]--;
        }
    }
}

void resume(int col) {
    for (int i = nodes[col].up; i != col; i = nodes[i].up) {
        for (int j = nodes[i].left; j != i; j = nodes[j].left) {
            nodes[nodes[j].up].down = j;
            nodes[nodes[j].down].up = j;
            col_ones[nodes[j].col]++;
        }
    }
    nodes[nodes[col].right].left = col;
    nodes[nodes[col].left].right = col;
}

void dance(int depth) {
    if (nodes[0].right == 0) {
        solved = true;
        return;
    }
    int c = nodes[0].right;
    for (int i = nodes[0].right; i != 0; i = nodes[i].right) {
        if (col_ones[i] < col_ones[c]) c = i;
    }
    remove(c);
    for (int i = nodes[c].down; i != c; i = nodes[i].down) {
        pushed_res.push_back(nodes[i].row-1);
        for (int j = nodes[i].right; j != i; j = nodes[j].right) remove(nodes[j].col);
        dance(depth + 1);
        if (solved) return;
        for (int j = nodes[i].left; j != i; j = nodes[j].left) resume(nodes[j].col);
        pushed_res.pop_back();
    }
    resume(c);
}

void set(int i, int j, int k) {
    int id = i*9 + j;
    int pid = id*9 + k;
    table[pid][i*9 + k] = 1;
    table[pid][81 + j*9 + k] = 1;
    int t = (i/3)*3 + j/3;
    table[pid][162 + t*9 + k] = 1;
    table[pid][243 + id] = 1;
}

void solve() {
    // build the link
    int m = 324, n = 729;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            table[i][j] = 0;
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] < 0) {
                for (int k = 0; k < 9; k++) set(i,j,k);
            } else {
                set(i, j, board[i][j]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        row_head_id[i] = -1;
    }
    nodes.resize(m+1);
    for (int i = 0; i <= m; i++) {
        nodes[i].left = i - 1;
        nodes[i].right = i + 1;
        nodes[i].up = i;
        nodes[i].down = i;
        nodes[i].row = -1;
        nodes[i].col = i;
        col_ones[i] = 0;
    }
    nodes[0].left = m;
    nodes[m].right = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!table[i][j]) continue;
            insert(i+1, j+1);
        }
    }
    pushed_res.clear();
    dance(0);
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &board[i][j]);
                board[i][j]--;
            }
        }
        solved = false;
        solve();
        for (int i = 0; i < pushed_res.size(); i++) {
            int pid = pushed_res[i];
            int row = pid/81, col = (pid/9) % 9, num = pid % 9;
            if (board[row][col] < 0) board[row][col] = num;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%d ", board[i][j] + 1);
            }
            printf("%d\n", board[i][8] + 1);
        }
    }
    return 0;
}
