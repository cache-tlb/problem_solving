
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dis(n, n+100);
        std::list<int> q;
        q.push_back(0);
        dis[0] = 0;
        int tail = 0;
        for (int idx = 0; idx < n; idx++) {
            int step = nums[idx];
            for (int i = tail + 1; i <= idx + step && i < n; i++) {
                dis[i] = std::min(dis[i], dis[idx] + 1);
            }
            tail = std::max(tail, idx + step);
        }
        return dis[n-1];
    }
};