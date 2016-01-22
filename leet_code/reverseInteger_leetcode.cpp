#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 0;
        while (x) {
            res = res*10 + (x%10);
            x /= 10;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.reverse(-123) << endl;
    return 0;
}
