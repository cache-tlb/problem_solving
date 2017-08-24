class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = 0;
        int pos = 0;
        while (pos < n.length()) {
            num = num*10 + n[pos] - '0';
            pos++;
        }
        long long tmp = num;
        int max_k = 0;
        while (tmp) {
            max_k++;
            tmp /= 2;
        }
        string ret = "";
        for (int trial = max_k; trial >= 1; trial--) {
            long long a = pow(num, 1./trial);
            if (a < 2) continue;
            long long x = 0;
            if (trial == 1) {
                x = num;
                a = num - 1;
            }
            else for (int i = 0; i <= trial; i++) {
                x = x*a+1;
            }
            if (x == num) {
                while (a) {
                    ret.insert(0, 1, char('0'+a%10));
                    a /= 10;
                }
                break;
            }
        }
        // std::cout << ret;
        return ret;
    }
};