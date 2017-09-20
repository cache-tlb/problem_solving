#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        std::vector<int> b(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &b[i]);
        }
        const int MAXB = 110;
        std::vector<int> cache1(MAXB, 0);
        for (int i = 1; i < N; i++) {
            std::vector<int> cache2(MAXB, 0);
            for (int a = 1; a <= b[i]; a+=std::max(b[i]-1, 1)) {
                int x = 0;
                for (int aa = 1; aa <= b[i-1]; aa+=std::max(b[i-1]-1,1)) {
                    x = std::max(x, abs(a-aa) + cache1[aa]);
                }
                cache2[a] = x;
                // std::cout << cache2[a] << ' ';
            }
            // std::cout << std::endl;
            cache1.swap(cache2);
        }
        int res = 0;
        for (int i = 1; i <= b[N-1]; i++) {
            res = std::max(res, cache1[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}
