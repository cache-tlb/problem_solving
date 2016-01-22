#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:

    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        int pos = -1;
        for (int i = n - 1; i > 0; i--) {
            if (num[i] > num[i - 1]) {
                pos = i - 1;
                break;
            }
        }
        if (pos < 0) {
            sort(num.begin(), num.end());
            return;
        }
        int val = num[pos];
        int cand = num[pos + 1];
        int candPos = pos + 1;
        for (int i = pos + 1; i < n; i++) {
            if (num[i] <= val) continue;
            cand = cand < num[i] ? cand : (candPos = i, num[i]);
        }
        swap(num[pos], num[candPos]);
        sort((vector<int>::iterator)&num[pos + 1], num.end());
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    int array[] = {1,3,2};
    vector<int> v(array);
    Solution s;
    s.nextPermutation(v);
    return 0;
}
