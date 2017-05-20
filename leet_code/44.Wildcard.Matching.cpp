#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        if (m==0 && n==0) return true;
        if (m > 0 && n==0) return false;
        if (m==0 && n > 0) {
            for (int i = 0; i < n; i++) {
                if (p[i] != '*') return false;
            }
            return true;
        }
        // m > 0 && n > 0
        std::vector<int> match((m+1)*(n+1), 0);
        match[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (p[i-1] == '*') {
                int first_j = -1;
                for (int j = 0; j <= m; j++) {
                    if (match[(i-1)*(m+1)+j]) {
                        first_j = j;
                        break;
                    }
                }
                if (first_j >= 0) {
                    for (int j = first_j; j <= m; j++) {
                        match[i*(m+1)+j] = 1;
                    }
                }
            } else if (p[i-1] == '?') {
                for (int j = 1; j <= m; j++) {
                    match[i*(m+1)+j] = match[(i-1)*(m+1)+j-1];
                }
            } else {
                for (int j = 1; j <= m; j++) {
                    if (p[i-1] == s[j-1])
                        match[i*(m+1)+j] = match[(i-1)*(m+1)+j-1];
                }
            }
        }
        return match[n*(m+1)+m];
    }
};
