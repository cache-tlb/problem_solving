class Solution {
public:
    std::unordered_map<int,int> left, right, num_set;
    void expand(int x) {
        if (left[x] != x || right[x] != x) return;
        std::list<int> q;
        int head = x;
        while (num_set.count(head)) {
            q.push_back(head);
            head--;
        }
        int tail = x + 1;
        while (num_set.count(tail)) {
            q.push_back(tail);
            tail++;
        }
        while (!q.empty()) {
            int i = q.back();
            q.pop_back();
            left[i] = head+1;
            right[i] = tail-1;
        }
    }
    int longestConsecutive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            num_set[nums[i]] = 1;
            left[nums[i]] = nums[i];
            right[nums[i]] = nums[i];
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            expand(nums[i]);
            res = std::max(res, right[nums[i]] - left[nums[i]]+1);
        }
        return res;
    }
};