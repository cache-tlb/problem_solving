#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solve(std::vector<int> &a) {
    while (!a.empty()) {
        if (a.size() <= 1) return true;
        int mid = (a.size() - 1)/2;
        int p = a[mid];
        int le = 0, gt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (i == mid) continue;
            if (a[i] <= p) le++;
            else gt++;
        }
        if (le < a.size() - 1 && gt < a.size() - 1) return false;
        std::vector<int> b;
        b.reserve(a.size() - 1);
        for (int i = 0; i < a.size(); i++) {
            if (i != mid) b.push_back(a[i]);
        }
        a.swap(b);
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A.large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        std::vector<int> v(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        bool ok = solve(v);
        const std::string yes = "YES", no = "NO";
        printf("Case #%d: %s\n", t, ok?yes.c_str():no.c_str());
    }
    return 0;
}
