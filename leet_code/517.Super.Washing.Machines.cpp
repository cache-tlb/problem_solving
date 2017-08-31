class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        if (!n) return 0;
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += machines[i];
        }
        int avg = s/n;
        if (avg*n != s) return -1;
        int res = 0;
        int acc = 0;
        for (int i = 0; i < n; i++) {
            int d = (machines[i] - avg);
            acc += d;
            res = std::max(res, abs(acc));
            if (d > 0) res = std::max(res, d);
        }
        return res;
    }
};