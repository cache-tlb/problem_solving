class Solution {
public:
    int gcd(int m, int n) { return n == 0 ? m : gcd(n, m % n); }
    bool isGoodArray(vector<int>& nums) {
        int d = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            d = gcd(d, nums[i]);            
            if (d == 1) break;
        }
        return d == 1;
    }
};
