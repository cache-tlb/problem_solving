class Solution {
public:
    struct Item {
        int pos, val;
        Item() {}
        Item(int p, int v) : pos(p), val(v) {}
    };
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        std::list<Item> stack;
        int res = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            int pos = i;
            while (!stack.empty() && h < stack.back().val) {
                Item item = stack.back();
                stack.pop_back();
                pos = item.pos;
                res = std::max(res, item.val*(i - item.pos));
            }
            stack.push_back(Item(pos, h));
        }
        return res;
    }
};