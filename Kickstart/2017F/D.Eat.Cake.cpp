#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

const int MAXN = 10010;
std::vector<int> cache;

struct Item {
    int step, val;
    Item () {}
    Item(int s, int v) : step(s), val(v) {}
};

void init() {
    cache.resize(MAXN, -1);
    std::list<Item> q;
    q.push_back(Item(0,0));
    while (!q.empty()) {
        Item item = q.front();
        q.pop_front();
        int v = item.val;
        int s = item.step;
        if (cache[v] >= 0) continue;
        cache[v] = s;
        for (int i = 1; v + i*i <= MAXN; i++) {
            int d = v + i*i;
            if (cache[d] < 0) q.push_back(Item(s+1, d));
        }
    }
}


int main() {
    // freopen("input.txt", "r", stdin);
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    init();
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        int res = cache[n];
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
