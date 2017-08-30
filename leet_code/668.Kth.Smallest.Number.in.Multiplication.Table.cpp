class Solution {
public:
    int find_le_num(int x, int m, int n) {
        int res = 0;
        for (int i = 1; i <= m; i++) {
            int q = x/i;
            if (q == 0) break;
            res += std::min(q, n);
        }
        return res;
    }
    int findKthNumber(int m, int n, int k) {
        if (m == 1 || n == 1) return k;
        if (k == 1 || k == m*n) return k;
        int low = 1, high = m*n;
        int res = 0;
        while (low <= high) {
            int mid = (low+high)/2;
            int mid_order = find_le_num(mid, m, n);
            int mid2_order = find_le_num(mid-1, m, n);
            if (mid2_order < k && k <= mid_order) {
                res = mid;
                break;
            }
            if (k > mid_order) low = mid + 1;
            else if (k <= mid2_order) high = mid - 1;
        }
        return res;
    }
};