#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i]-1 < n && nums[i] != nums[nums[i]-1]) {
                std::swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return n + 1;
    }
};