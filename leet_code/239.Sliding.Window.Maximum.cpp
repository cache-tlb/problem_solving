class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k==1) return nums;
        std::vector<int> res;
        std::list<int> q;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!q.empty() && q.front()+k <= i) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};