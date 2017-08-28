#include <cstdio>
#include <vector>

const int MAXN = 105;

struct Node {
    int up, down, left, right, row, col;
    Node() {}
};

bool solved = false;
int n, m;
int table[MAXN][MAXN];
int row_head_id[MAXN];
int col_ones[MAXN];
std::vector<Node> nodes;

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
        for (int j = nodes[i].right; j != i; j = nodes[j].right) remove(nodes[j].col);
        dance(depth + 1);
        if (solved) return;
        for (int j = nodes[i].left; j != i; j = nodes[j].left) resume(nodes[j].col);
    }
    resume(c);
}

void solve() {
    // build the link
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
    dance(0);
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &table[i][j]);
            }
        }
        solved = false;
        solve();
        if (solved) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
