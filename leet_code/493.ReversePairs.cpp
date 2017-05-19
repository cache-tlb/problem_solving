class Solution {
public:
    int solve(int *a, int n, int *buf) {
        // count the number of pair and sort the array
        if (n <= 1) return 0;
        int pivot = n/2;
        int *a1 = a, *a2 = a+pivot;
        int n1 = pivot, n2 = n - pivot;
        int c1 = solve(a1, n1, buf), c2 = solve(a2, n2, buf);
        int cross = 0;
        // first count it, then sort it
        int x = 0, y = 0;
        while (x < n1) {
            while (y < n2 && (long long)a1[x] > 2*(long long)(a2[y])) y++;
            cross += y;
            x++;
        }

        int p1 = 0, p2 = 0;
        int p = 0;
        while (p1 < n1 && p2 < n2) {
            if (a1[p1] < a2[p2]) {
                buf[p++] = a1[p1++];
            } else {
                buf[p++] = a2[p2++];
            }
        }
        while (p1 < n1) {
            buf[p++] = a1[p1++];
        }
        while (p2 < n2) {
            buf[p++] = a2[p2++];
        }
        for (int i = 0; i < n; i++) {
            a[i] = buf[i];
        }

        return c1 + c2 + cross;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        std::vector<int> buf(n);
        return solve(&nums[0], n, &buf[0]);
    }
};
