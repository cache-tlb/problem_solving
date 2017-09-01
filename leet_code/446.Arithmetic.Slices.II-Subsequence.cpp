class Solution {
public:
    std::vector<std::unordered_map<long long,int> > prefix;
    int n;
    int numberOfArithmeticSlices(vector<int>& A) {
        n = A.size();
        prefix.resize(n);
        for (int i = 0; i < n; i++) {
            long long x = A[i];
            for (int j = i - 1; j >= 0; j--) {
                long long y = A[j];
                long long d = x - y;
                if (prefix[j].count(d) == 0) {
                    prefix[i][d]++;
                } else {
                    prefix[i][d] += prefix[j][d] + 1;
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (auto it = prefix[i].begin(); it != prefix[i].end(); it++) {
                res += it->second;
            }
        }
        // printf("%d\n", res);
        // printf("%d\n", ((n-1)*n)/2);
        res -= ((n-1)*n)/2;
        return res;
    }
};