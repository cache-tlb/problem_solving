#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        typedef pair<int,int> pii;
        int n = numbers.size();
        std::vector<pii> pairs(n);
        for (int i = 0; i < n; i++) pairs[i] = pii(numbers[i], i + 1);
        sort(pairs.begin(), pairs.end(), [](const pii&a, const pii&b) -> bool {return a.first < b.first || (a.first == b.first && a.second < b.second);});
        int i = 0, j = n - 1;
        vector<int> ans(2);
        while(i < j) {
            int sum = pairs[i].first + pairs[j].first;
            if(sum == target) {
                ans[0] = pairs[i].second, ans[1] = pairs[j].second;
                break;
            }
            else if (sum > target) j--;
            else i++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {150,24,79,50,88,345,3};
    std::vector<int> v(a, a + sizeof(a)/sizeof(int));
    int target = 200;
    Solution s;
    std::vector<int> ans = s.twoSum(v, target);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
