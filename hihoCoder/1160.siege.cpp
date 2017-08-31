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

const int MAXN = 1000000 + 5;

std::vector<int> father, num;
void makeSet(int n) {
    for(int j = 1; j <= n; j++) {
        father[j] = j;
        num[j] = 1;
    }
}
int findSet(int x) {
    if(father[x] != x) {
        father[x] = findSet(father[x]);
    }
    return father[x];
}
void Union(int a, int b) {
    int x = findSet(a);
    int y = findSet(b);
    if(x == y) return;
    if(num[x] <= num[y]) {
        father[x] = y;
        num[y] += num[x];
    } else {
        father[y] = x;
        num[x] += num[y];
    }
}

struct Item {
    int w, id;
    Item() {}
    Item(int ww, int ii) : w(ww), id(ii) {} 
};

int main() {
    // freopen("input.txt", "r", stdin);
    father.resize(MAXN);
    num.resize(MAXN);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int x, y;
        long long res = 0;
        std::vector<Item> uncharted;
        uncharted.reserve(n+1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            res += x;
            uncharted.push_back(Item(x, i));
        }
        makeSet(n);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            Union(x, y);
        }
        std::sort(uncharted.begin(), uncharted.end(), [](const Item &a, const Item &b) {
            return a.w < b.w || (a.w == b.w && a.id < b.id);
        });
        std::vector<int> set_size(n+1, 0);
        for (int i = 1; i <= n; i++) {
            int set_id = findSet(i);
            set_size[set_id]++;
        }
        int added_edge = 0;
        while (!uncharted.empty() && added_edge + k < m) {
            Item item = uncharted.back();
            uncharted.pop_back();;
            int set_id = findSet(item.id);
            if (set_size[set_id] <= 1) continue;
            set_size[set_id]--;
            added_edge++;
            res -= item.w;
        }
        printf("Case #%d: %lld\n", t, res);
    }
    return 0;
}