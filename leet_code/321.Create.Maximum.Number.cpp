class Solution {
public:
    std::vector<int> nums1, nums2;
    std::vector<int> cand1, cand2;
    std::vector<int> cand_res;
    std::vector<int> res;
    void refresh_res() {
        if (res.size() < cand_res.size()) {
            res.swap(cand_res);
            return;
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] < cand_res[i]) {
                res.swap(cand_res);
                return;
            } else if (res[i] > cand_res[i]) return;
        }
    }
    void find1(int k, const std::vector<int> &nums, std::vector<int> &ret) {
        ret.clear();
        int n = nums.size();
        if (k == 0) return;
        std::vector<std::vector<int> > digit_pos(10);
        for (int i = n - 1; i >= 0; i--) {
            digit_pos[nums[i]].push_back(i);
        }
        int cur = 0;
        int n_discard = 0, max_discard = n - k;
        while (ret.size() < k) {
            int max_d = 0;
            for (int d = 9; d >= 0; d--) {
                while (!digit_pos[d].empty() && digit_pos[d].back() < cur) digit_pos[d].pop_back();
                if (digit_pos[d].empty()) continue;
                if (digit_pos[d].back() - cur <= max_discard) {
                    max_d = d;
                    break;
                }
            }
            ret.push_back(max_d);
            max_discard -= (digit_pos[max_d].back()-cur);
            cur = digit_pos[max_d].back() + 1;
        }
    }
    void find(int k1, int k2) {
        if (k1 > nums1.size() || k2 > nums2.size()) return;
        find1(k1, nums1, cand1);
        find1(k2, nums2, cand2);
        int p = 0, p1 = 0, p2 = 0;
        cand_res.clear();
        while (p1 < k1 && p2 < k2) {
            if (cand1[p1] > cand2[p2]) cand_res.push_back(cand1[p1++]);
            else if (cand1[p1] < cand2[p2]) cand_res.push_back(cand2[p2++]);
            else {
                int c1 = p1, c2 = p2, v = cand1[p1];
                while (c1 < k1 && c2 < k2 && cand1[c1] >= v && cand2[c2] >= v && cand1[c1] == cand2[c2]) {
                    c1++;
                    c2++;
                }
                if (c1 >= k1 && c2 >= k2) cand_res.push_back(cand1[p1++]);
                else if (c1 >= k1 && c2 < k2) cand_res.push_back(cand2[p2++]);
                else if (c1 < k1 && c2 >= k2) cand_res.push_back(cand1[p1++]);
                else {
                    if (cand1[c1] > cand2[c2]) cand_res.push_back(cand1[p1++]);
                    else cand_res.push_back(cand2[p2++]);
                }
            }
        }
        while (p1 < k1) cand_res.push_back(cand1[p1++]);
        while (p2 < k2) cand_res.push_back(cand2[p2++]);
        refresh_res();
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int i = 0; i <= k; i++) {
            // nums1: i, nums2: k-i
            find(i, k-i);
        }
        return res;
    }
};