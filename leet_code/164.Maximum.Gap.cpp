class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int max_val = 0, min_val = INT_MAX;
        int n = nums.size();
        if (n <= 1) return 0;
        for (int i = 0; i < n; i++) {
            max_val = std::max(max_val, nums[i]);
            min_val = std::min(min_val, nums[i]);
        }
        int bkt_size = std::max((max_val - min_val) / (n - 1), 1);
        int bkt_num = (max_val - min_val)/bkt_size + 1;
        std::vector<int> bkt_max(bkt_num, min_val);
        std::vector<int> bkt_min(bkt_num, max_val);
        std::vector<bool> bkt_empty(bkt_num, true);
        for (int i = 0; i < n; i++) {
            int bkt_id = (nums[i] - min_val) / bkt_size;
            bkt_max[bkt_id] = std::max(nums[i], bkt_max[bkt_id]);
            bkt_min[bkt_id] = std::min(nums[i], bkt_min[bkt_id]);
            bkt_empty[bkt_id] = false;
        }
        int res = 0;
        int last_max = bkt_max[0];
        for (int i = 1; i < bkt_num; i++) {
            if (!bkt_empty[i]) {
                res = std::max(res, bkt_min[i] - last_max);
                last_max = bkt_max[i];
            }
        }
        return res;
    }
};