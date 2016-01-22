#include <vector>
#include <set>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==1) return vector<string>(1,"()");
        set<string> s;
        for (int k = 1; k <= n / 2; k++){
            vector<string> v1 = generateParenthesis(n - k);
            vector<string> v2 = generateParenthesis(k);
            int sz1 = v1.size();
            int sz2 = v2.size();
            for (int i = 0; i < sz1; i++) {
                for (int j = 0; j < sz2; j++) {
                    for (int n1 = 0; n1 <= 2*k; n1++) {
                        int n2 = 2*k - n1;
                        string &str = v2[j];
                        s.insert(str.substr(0, n1) + v1[i] + str.substr(n1, n2));
                    }
                }
            }
        }
        vector<string> ret(s.begin(), s.end());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
