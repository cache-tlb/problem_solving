class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        std::vector<int> left(n), right(n);
        int left_val = height.front();
        int right_val = height.back();
        for (int i = 1; i < n - 1; i++) {
            left_val = std::max(left_val, height[i]);
            left[i] = left_val;
            right_val = std::max(right_val, height[n - 1 - i]);
            right[n - 1 - i] = right_val;
        }
        int s = 0;
        for (int i = 1; i < n - 1; i++) {
            int water = std::min(left[i], right[i]);
            if (water > height[i])
                s += (water - height[i]);
        }
        return s;
    }
};