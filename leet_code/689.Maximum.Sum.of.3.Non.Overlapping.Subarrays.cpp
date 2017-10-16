class Solution {
public:
    template<int N> struct Item {
        int ids[N];
        long long val;
        Item() : val(0) {}
    };
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long long> sum(n - k + 1, 0);
        long long cur_s = 0;
        for (int i = 0; i < k - 1; i++) {
            cur_s += nums[i];
        }
        for (int i = 0; i < sum.size(); i++) {
            cur_s += nums[k-1+i];
            sum[i] = cur_s;
            cur_s -= nums[i];
        }
        std::vector<Item<1> > item1s(n - k + 1);
        long long max_sum = 0;
        int max_start = 0;
        for (int i = 0; i < n - k + 1; i++) {
            if (sum[i] > max_sum) {
                max_sum = sum[i];
                max_start = i;
            }
            item1s[i].val = max_sum;
            item1s[i].ids[0] = max_start;
        }
        std::vector<Item<2> > item2s(n - k + 1);
        max_sum = 0;
        max_start = 0;
        Item<1> max_last1 = Item<1>();
        for (int i = 0; i < n - k + 1; i++) {
            if (i < k) continue;
            long long s = sum[i] + item1s[i-k].val;
            if (s > max_sum) {
                max_sum = s;
                max_start = i;
                max_last1 = item1s[i-k];
            }
            item2s[i].ids[0] = max_last1.ids[0];
            item2s[i].ids[1] = max_start;
            item2s[i].val = max_sum;
        }
        max_sum = 0;
        max_start = 0;
        Item<2> max_last2 = Item<2>();
        std::vector<Item<3> > item3s(n - k + 1);
        for (int i = 0; i < n - k + 1; i++) {
            if (i < k*2) continue;
            long long s = sum[i] + item2s[i-k].val;
            if (s > max_sum) {
                max_sum = s;
                max_start = i;
                max_last2 = item2s[i-k];
            }
            item3s[i].ids[0] = max_last2.ids[0];
            item3s[i].ids[1] = max_last2.ids[1];
            item3s[i].ids[2] = max_start;
            item3s[i].val = max_sum;
        }
        Item<3> item = item3s.back();
        vector<int> ret(3);
        ret[0] = item.ids[0];
        ret[1] = item.ids[1];
        ret[2] = item.ids[2];
        // printf("%d %d %d\n", ret[0], ret[1], ret[2]);
        return ret;
    }
};