class Solution {
public:
    int find(int *a, int n) {
        if (n == 1) return a[0];
        if (n == 2) return std::min(a[0], a[1]);
        int p = n / 2;
        if (a[0] < a[p]) return std::min(a[0], find(a+p, n-p));
        else if (a[0] > a[p]) return find(a, p+1);
        else return std::min(find(a, p), find(a+p,n-p));
    }
    int findMin(vector<int>& nums) {
        return find(&nums[0], nums.size());
    }
};