#include <cstdio>
#include <vector>

 int main() {
    //  freopen("input.txt", "r", stdin);
     int n,m;
     scanf("%d%d", &n, &m);
     std::vector<int> w, p;
     w.resize(n);
     p.resize(n);
     int tw = 11;
     std::vector<int> table(tw*tw, 0);
     for (int i = 0; i < n; i++) {
         scanf("%d%d", &w[i], &p[i]);
         table[w[i]*tw+p[i]]++;
     }
     std::vector<int> pp, ww;
     for (int i = 0; i < table.size(); i++) {
         if (table[i] == 0) continue;
         int k = table[i], cur = 1;
         int weight = i/tw, price = i%tw;
         while (k >= cur) {
             pp.push_back(cur*price);
             ww.push_back(cur*weight);
             k -= cur;
             cur *= 2;
         }
         if (k) {
             pp.push_back(k*price);
             ww.push_back(k*weight);
         }
     }

     n = pp.size();
     std::vector<int> cache1(m+1, 0);
     int sum_weight = 0;
     for (int i = 0; i < n; i++) {
         sum_weight += ww[i];
     }
     for (int i = 0; i < n; i++) {
         if (i > 0) sum_weight -= ww[i-1];
         int upper = std::max(ww[i], m-sum_weight);
        // int upper = w[i];
         for (int j = m; j >= upper; j--) {
             cache1[j] = std::max(cache1[j], cache1[j-ww[i]]+pp[i]);
         }
     }
     int res = 0;
     for (int i = 0; i <= m; i++) res = std::max(res, cache1[i]);
     printf("%d\n", res);
     return 0;
 }