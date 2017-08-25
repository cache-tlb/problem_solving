class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long cur_sum = 0;
        int res = 0;
        int m = 0;
        while (true) {
            while (m < nums.size() && cur_sum >= nums[m] - 1) {
                cur_sum += nums[m];
                m++;
            }
            if (cur_sum >= n) break;
            int patch_val = cur_sum + 1;
            // std::cout << patch_val << std::endl;
            cur_sum = cur_sum*2+1;
            res++;
        }
        // std:: cout << res;
        return res;
    }
};