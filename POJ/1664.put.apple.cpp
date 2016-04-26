#include <cstdio>

const int MAXN = 12;
int cache[MAXN][MAXN][MAXN] = {};
int visit[MAXN][MAXN][MAXN] = {};

int query(int m, int n, int l) {
    if (visit[m][n][l]) return cache[m][n][l];
    else {
        int x = 0;
        if (m == 0 || n == 0) x = 0;
        else if (l > m) x = 0;
        else if (m == 1 || n == 1) x = 1;
        else {
            for (int i = l; i <= m; i++) {
                if (m - i < 0) continue;
                x += query(m - i, n - 1, i);
            }
        }
        visit[m][n][l] = 1;
        cache[m][n][l] = x;
    }
    return cache[m][n][l];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &m, &n);
        printf("%d\n", query(m, n, 0));
    }
    return 0;
}

/*放苹果
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 29867        Accepted: 18840
Description

把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
Input

第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
Output

对输入的每组数据M和N，用一行输出相应的K。
Sample Input

1
7 3
Sample Output

8
Source*/