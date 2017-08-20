class Solution {
public:
    struct Item {
        int val, index;
        Item() {}
        Item(int v, int i) : val(v), index(i) {}
    };
    struct cmp {
        bool operator () (const Item &a, const Item &b) {
            return (a.val > b.val) || (a.val == b.val && a.index < b.index);
        }
    };
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        std::map<Item, int, cmp> table;
        std::vector<int> water(n, -1);
        for (int i = 0; i < n; i++) {
            table[Item(height[i], i)] = 1;
        }
        std::map<Item, int>::iterator it = table.begin();
        Item item = it->first;
        int left = item.index;
        int right = item.index;
        // water[item.index] = item.val;
        // table.erase(it);
        while (!table.empty()) {
            std::map<Item, int>::iterator it2 = table.begin();
            Item item2 = it2->first;
            int start = item2.index, end = item2.index;
            if (item2.index > right) start = right + 1;
            else if (item2.index < left) end = left - 1;
            for (int i = start; i <= end; i++) {
                water[i] = item2.val;
                table.erase(Item(height[i], i));
            }
            left = std::min(left, item2.index);
            right = std::max(right, item2.index);
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += (water[i] - height[i]);
        }
        return s;
    }
};