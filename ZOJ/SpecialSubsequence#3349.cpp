#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

#define inf 1<<28
#define N 100005
#define lson step<<1
#define rson step<<1|1

using namespace std;

struct Node {
    int left, right;
    int mx;
} L[N*4];

int dp[N],a[N],b[N];

void Build(int step, int l, int r) {
    L[step].left = l;
    L[step].right = r;
    L[step].mx = 0;
    if(l == r) return ;
    int m = (l + r) >> 1;
    Build(lson, l, m);
    Build(rson, m + 1, r);
}

void Update(int step, int pos, int val) {
    if(L[step].left == L[step].right) {
        L[step].mx = val;
        return;
    }
    int m = (L[step].left + L[step].right) >> 1;
    if(pos <= m) Update(lson, pos, val);
    else Update(rson, pos, val);
    L[step].mx = max(L[lson].mx, L[rson].mx);
}

int Query(int step, int l, int r) {
    if(L[step].left == l && L[step].right == r)
        return L[step].mx;
    int m = (L[step].left + L[step].right) >> 1;
    if(r <= m) return Query(lson, l, r);
    else if(l > m) return Query(rson, l, r);
    else return max(Query(lson, l, m), Query(rson, m + 1, r));
}

int main()
{
    int n,d;
    while(scanf("%d%d", &n, &d) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b + n);
        int m = unique(b, b + n) - b;
        Build(1, 0, m - 1);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int l = lower_bound(b, b + m, a[i] - d) - b;
            int r = upper_bound(b, b + m, a[i] + d) - b - 1;
            int q = Query(1, l, r);
            ans = max(ans, q + 1);
            Update(1, lower_bound(b, b+m, a[i]) - b, q + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
