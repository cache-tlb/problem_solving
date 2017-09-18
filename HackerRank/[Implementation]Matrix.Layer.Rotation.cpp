#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m, n, r;
    scanf("%d%d%d", &m, &n, &r);
    std::vector<std::vector<int> > a(m, std::vector<int>(n));
    std::vector<std::vector<int> > b = a;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int head_row = 0, tail_row = m - 1;
    int head_col = 0, tail_col = n - 1;
    while (head_row < tail_row && head_col < tail_col) {
        int k = 2*((tail_row - head_row) + (tail_col - head_col));
        std::vector<int> layer(k);
        int rem = r % k;
        int i = head_row, j = head_col;
        int index = 0;
        for (i = head_row; i < tail_row; i++) {
            int pos = (index + rem) % k;
            layer[pos] = a[i][j];
            index++;
        }
        i = tail_row;
        for (j = head_col; j < tail_col; j++) {
            int pos = (index + rem) % k;
            layer[pos] = a[i][j];
            index++;
        }
        j = tail_col;
        for (i = tail_row; i > head_row; i--) {
            int pos = (index + rem) % k;
            layer[pos] = a[i][j];
            index++;
        }
        i = head_row;
        for (j = tail_col; j > head_col; j--) {
            int pos = (index + rem) % k;
            layer[pos] = a[i][j];
            index++;
        }

        index = 0;
        for (i = head_row; i < tail_row; i++) {
            b[i][j] = layer[index++];
        }
        i = tail_row;
        for (j = head_col; j < tail_col; j++) {
            b[i][j] = layer[index++];
        }
        j = tail_col;
        for (i = tail_row; i > head_row; i--) {
            b[i][j] = layer[index++];
        }
        i = head_row;
        for (j = tail_col; j > head_col; j--) {
            b[i][j] = layer[index++];
        }

        head_row++;
        tail_row--;
        head_col++;
        tail_col--;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%d ", b[i][j]);
        }
        printf("%d\n", b[i][n-1]);
    }
    return 0;
}
