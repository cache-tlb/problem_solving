class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return 1.0;
        if (x == 0) return 0;
        if (n==0) return 1;
        if (n==1) return x;
        if (x > 0 && x < 1 && n > 2147483646) return 0;
        if (x > 1 && n < -2147483646) return 0;
        if (x < 0) {
            int m = (n % 2 + 2) % 2;
            if (m == 0) return myPow(-x, n);
            else return -1.0*myPow(-x,n);
        }
        if (n < 0) return myPow(1./x,-n);
        int m = n/2;
        double tmp = myPow(x, m);
        tmp *= tmp;
        if (n % 2 == 1) tmp *= x;
        return tmp;
    }
};