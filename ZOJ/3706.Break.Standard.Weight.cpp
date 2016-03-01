#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

int query(int a, int b, int c) {
    set<int> cand;
    cand.insert(a);
    cand.insert(b);
    cand.insert(c);

    cand.insert(a+b);
    cand.insert(a+c);
    cand.insert(b+c);
    cand.insert(abs(a-b));
    cand.insert(abs(a-c));
    cand.insert(abs(c-b));

    cand.insert(abs(a+b-c));
    cand.insert(abs(a-b+c));
    cand.insert(abs(-a+b+c));

    cand.insert(a+b+c);

    if (cand.count(0) > 0) return cand.size() - 1;
    else return cand.size();
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int res = 0;
        for (int i = 1; i <= x - 1; i++) {
            res = max(res, query(i, x - i, y));
        }
        for (int j = 0; j <= y - 1; j++) {
            res = max(res, query(x, j, y - j));
        }
        printf("%d\n", res);
    }
    return 0;
}
