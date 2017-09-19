#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long find_reverse_pairs(int *a, int *buf, int n) {
    if (n <= 1) return 0;
    int pivot = n/2;
    long long l_res = find_reverse_pairs(a, buf, pivot);
    long long r_res = find_reverse_pairs(a + pivot, buf + pivot, n - pivot);
    int p = 0, p1 = 0, p2 = pivot;
    long long count = 0;
    while (p1 < pivot && p2 < n) {
        if (a[p1] <= a[p2]) buf[p++] = a[p1++];
        else {
            //  (a[p1] > a[p2]) 
            buf[p++] = a[p2++];
            count += (pivot - p1);
        }
    }
    while (p1 < pivot) buf[p++] = a[p1++];
    while (p2 < n) buf[p++] = a[p2++];
    for (int i = 0; i < n; i++) {
        a[i] = buf[i];
    }
    return l_res + r_res + count;
}

long long solve(const std::vector<int> &a) {
    std::vector<int> b = a;
    std::vector<int> buf = a;
    return find_reverse_pairs(&b[0], &buf[0], a.size());
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("%lld\n", solve(a));
    }
    return 0;
}
