#include <cmath>
#include <cstdio>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; i++) {
            if (A[i] <= 0 || A[i] >= n + 1) A[i] = n + 2;
        }
        for (int i = 0; i < n; i++) {
            int index = abs(A[i]);
            if (index >= 1 && index <= n && A[index - 1] > 0) A[index - 1] *= -1;
        }
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            if (A[i] > 0) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
