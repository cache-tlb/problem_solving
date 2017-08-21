class Solution {
public:
    int first_digit(int x) {
        while (x >= 10) {
            x /= 10;
        }
        return x;
    }
    int num_digit(int x) {
        int n = 0;
        while (x) {
            x /= 10;
            n++;
        }
        return n;
    }
    int ex10(int x) {
        int ret = 1;
        while (x) {
            x--;
            ret *= 10;
        }
        return ret;
    }
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        if (n < 10) return 1;
        int d = first_digit(n);
        int nd = num_digit(n);
        int res = 0;
        int batch = ex10(nd-1);
        int batch2 = ex10(nd-2);
        std::cout << "batch:" << batch << std::endl;
        if (d > 1) {
            res += (batch + batch2*(nd-1)*d);
        } else {
            res += (n - batch + 1 + batch2*(nd-1));
        }
        res += countDigitOne(n - d*batch);
        // std::cout << res << std::endl;
        return res;
    }
};