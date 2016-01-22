#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int _dividend, int _divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long q = 0;
        int sign = 1;
        long long dividend = _dividend;
        long long divisor = _divisor;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = -1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend > 0) {
            long long d = divisor;
            long long qq = 1;
            while (d + d <= dividend) d = d + d, qq = qq + qq;
            q += qq;
            dividend -= d;
            if (dividend < 0) q-=qq;
        }
        return int(sign < 0 ? -q : q);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    cout << s.divide(2147483647, 2) << endl;
    return 0;
}
