#include <iostream>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *ptr = str;
        while (*ptr == ' ') ptr++;
        int ret = 0;
        int sign = 1;
        int state = 0;
        int halt = 0;
        long long acc = 0;
        while(*ptr && !halt) {
            switch (state) {
            case 0:
                if (*ptr == '+') state = 2;
                else if (*ptr == '-') sign = -1, state = 3;
                else if (*ptr >= '0' && *ptr <= '9'){
                    acc = acc * 10 + (*ptr - '0');
                    state = 1;
                    if (sign == 1 && acc > 2147483647) acc = 2147483647, state = 4;
                    else if (sign == -1 && acc > 2147483648) acc = 2147483648, state = 4;
                }
                else state = 4;
                break;
            case 1:
                if (*ptr >= '0' && *ptr <= '9'){
                    acc = acc * 10 + (*ptr - '0');
                    state = 1;
                    if (sign == 1 && acc > 2147483647) acc = 2147483647, state = 4;
                    else if (sign == -1 && acc > 2147483648) acc = 2147483648, state = 4;
                }
                else state = 4;
                break;
            case 2:
            case 3:
                if (*ptr >= '0' && *ptr <= '9') state = 1, ptr--;
                else state = 4;
                break;
            case 4:
                halt = 1;
                break;
            default:
                break;
            }
            ptr++;
        }
        ret = int(acc * sign);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.atoi("       -2147483649   ") << endl;
    return 0;
}
