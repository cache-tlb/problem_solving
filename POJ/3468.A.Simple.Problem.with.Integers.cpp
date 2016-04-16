// give up
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
int const MAX = 1e5 + 5;
ll sum[MAX << 2], add[MAX << 2];

void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void PushDown(int ln, int rn, int rt)
{
    if(add[rt])
    {
        sum[rt << 1] += (ll)ln * add[rt];
        sum[rt << 1 | 1] += (ll)rn * add[rt];
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
    return;
}

void Build(int l, int r, int rt)
{
    add[rt] = 0;
    if(l == r)
    {
        scanf("%lld", &sum[rt]);
        return;
    }
    int mid = (l + r) >> 1;
    Build(lson);
    Build(rson);
    PushUp(rt);
    return;
}

void Update(int L, int R, int c, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        sum[rt] += (r - l + 1) * c;
        add[rt] += c;
        return;
    }
    int mid = (l + r) >> 1;
    PushDown(mid - l + 1, r - mid, rt);
    if(L <= mid)
        Update(L, R, c, lson);
    if(R > mid)
        Update(L, R, c, rson);
    PushUp(rt);
    return;
}

ll Query(int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R)
        return sum[rt];
    int mid = (l + r) >> 1;
    PushDown(mid - l + 1, r - mid, rt);
    ll ans = 0;
    if(L <= mid)
        ans += Query(L, R, lson);
    if(R > mid)
        ans += Query(L, R, rson);
    return ans;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    Build(1, n, 1);
    while(q --)
    {
        char s[2];
        scanf("%s", s);
        if(s[0] == 'Q')
        {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", Query(l, r, 1, n, 1));
        }
        else 
        {
            int l, r, c;
            scanf("%d %d %d", &l, &r, &c);
            Update(l, r, c, 1, n, 1);
        }
    }
}
/*
Sample Input

10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output

4
55
9
15
*/
