#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int MAXV = 10010;
std::vector<int> cache;

struct Item {
    int step, val;
    Item () {}
    Item(int s, int v) : step(s), val(v) {}
};

void init() {
    cache.resize(MAXV, -1);
    std::list<Item> q;
    q.push_back(Item(0,0));
    while (!q.empty()) {
        Item item = q.front();
        q.pop_front();
        int v = item.val;
        int s = item.step;
        if (cache[v] >= 0) continue;
        cache[v] = s;
        if (cache[v+1] < 0) q.push_back(Item(s+1, v+1));
        if (cache[v+2] < 0) q.push_back(Item(s+1, v+2));
        if (cache[v+5] < 0) q.push_back(Item(s+1, v+5));
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        std::vector<int> a(N);
        int min_v = -1;
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
            if (min_v < 0 || min_v > a[i]) min_v = a[i];
        }
        for (int i = 0; i < N; i++) {
            a[i] -= min_v;
        }
        int s[6] = {};
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < 6; k++) {
                s[k] += cache[a[i] + k];
            }
        }
        int ss = s[0];
        for (int k = 1; k < 6; k++) {
            ss = std::min(ss, s[k]);
        }
        printf("%d\n", ss);
    }
    return 0;
}
