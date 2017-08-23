class Solution {
public:
    static const int N = 40;
    int table[N], acc[N];
    int find(std::vector<int> &ds) {
        if (ds.empty()) return 1;
        if (ds.size() == 1) return 2;
        if (ds.size() == 2) return 3;
        int x = acc[ds.size()-1];
        ds.pop_back();
        int y = 0;
        if (ds.back() == 1) y = acc[ds.size()-1];
        else {
            while (!ds.empty() && ds.back() == 0) ds.pop_back();
            y = find(ds);
        }
        return x + y;
    }
    int findIntegers(int num) {
        table[0] = 1;
        table[1] = 1;
        table[2] = 1;
        int s = table[0];
        for (int k = 3; k < N; k++) {
            table[k] = table[k-2] + s;
            s += table[k-2];
        }
        s = 0;
        for (int i = 0; i < N; i++) {
            s += table[i];
            acc[i] = s;
        }
        int n = num;
        int d = 0;
        std::vector<int> ds;
        while (n) {
            ds.push_back(n%2);
            n /= 2;
            d++;
        }
        return find(ds);
    }
};