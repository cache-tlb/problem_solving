class Solution {
public:
    struct Item {
        int row, col, val;
        Item() {}
        Item(int v, int r, int c) : val(v), row(r), col(c) {}
    };
    struct cmp {
        bool operator () (const Item &a, const Item &b) {
            return (a.val < b.val) || (a.val == b.val && a.row < b.row);
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        std::map<Item, int, cmp> current_set;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            current_set[Item(nums[i][0], i, 0)] = 1;
        }
        int min_head = 0, min_tail = 0, min_len = 1000000;
        while (true) {
            std::map<Item,int>::iterator first_it = current_set.begin();
            std::map<Item,int>::reverse_iterator last_it = current_set.rbegin();
            Item first_item = first_it->first, last_item = last_it->first;
            int head = first_item.val, tail = last_item.val;
            int current_len = tail - head + 1;
            if (current_len < min_len) {
                min_head = head;
                min_tail = tail;
                min_len = current_len;
            }
            int i = first_item.row, j = first_item.col;
            if (j + 1 >= nums[i].size()) break;
            current_set.erase(first_it);
            current_set[Item(nums[i][j+1], i, j + 1)] = 1;
        }
        std::vector<int> res;
        res.push_back(min_head);
        res.push_back(min_tail);
        return res;
    }
};