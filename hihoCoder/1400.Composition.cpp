#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <cstring>
#include <map>
#include <set>

using namespace std;
int ban[26][26];

int main() {
    // freopen("input.txt", "r", stdin);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            ban[i][j] = 0;
        }
    }
    int N, m;
    scanf("%d", &N);
    char *str = new char[N+1];
    scanf("%s", str);
    scanf("%d", &m);
    char token[16];
    for (int i = 0; i < m; i++) {
        scanf("%s", token);
        int id1 = token[0] - 'a', id2 = token[1] - 'a';
        ban[id1][id2] = 1;
        ban[id2][id1] = 1;
    }
    std::vector<int> last_pos(26,-1);
    std::vector<int> dp(N, 0);
    for (int i = 0; i < N; i++) {
        int c = str[i] - 'a';
        int max_len = 0;
        for (int last_c = 0; last_c < 26; last_c++) {
            if (ban[c][last_c]) continue;
            if (last_pos[last_c] < 0) continue;
            max_len = std::max(max_len, dp[last_pos[last_c]]);
        }
        dp[i] = 1 + max_len;
        last_pos[c] = i;
    }
    int max_len = 0;
    for (int i = 0; i < N; i++) {
        max_len = std::max(max_len, dp[i]);
    }
    // printf("%d %d\n", N, max_len);
    printf("%d\n", N - max_len);
    return 0;
}