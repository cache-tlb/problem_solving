#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int solve(int E, std::vector<int> &skill) {
    std::sort(skill.begin(), skill.end());
    if (skill.empty() || E <= skill[0]) return 0;
    int res = 0;
    int n = skill.size();
    for (int i = 0; i < n; i++) {
        long long rem = E;
        for (int j = 0; j < i; j++) {
            rem += skill[n - 1 - j];
        }
        int h = 0;
        for (int j = 0; j < n - i; j++) {
            if (rem > skill[j]) h++;
            rem -= skill[j];
        }
        h -= i;
        res = std::max(h, res);
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int E, N;
        scanf("%d%d", &E, &N);
        std::vector<int> skill(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &skill[i]);
        }
        int res = solve(E, skill);
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
