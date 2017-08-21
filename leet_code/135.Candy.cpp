/*class Solution {
public:
    struct Item {
        int idx, val;
        Item(int i, int v) : idx(i), val(v) {}
    };
    struct cmp {
        bool operator () (const Item &a, const Item &b) {
            return (a.val < b.val) || (a.val== b.val && a.idx < b.idx);
        }
    };
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        std::map<Item,int,cmp> table;
        for (int i = 0; i < n; i++) {
            table[Item(i, ratings[i])] = 1;
        }
        std::vector<int> candy(n, -1);
        while (!table.empty()) {
            Item item = (table.begin())->first;
            table.erase(item);
            int idx = item.idx;
            int num = 1;
            if (idx - 1 >= 0 && candy[idx-1] > 0 && ratings[idx] > ratings[idx-1]) 
                num = std::max(num, candy[idx-1] + 1);
            if (idx + 1 < n && candy[idx+1] > 0 && ratings[idx] > ratings[idx+1]) 
                num = std::max(num, candy[idx+1] + 1);
            candy[idx] = num;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += candy[i];
        }
        return res;
    }
};
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        std::vector<int> candy(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) candy[i] = candy[i-1]+1;
        }
        for (int i = n - 1; i >= 1; i--) {
            if (ratings[i-1] > ratings[i]) candy[i-1] = std::max(candy[i-1], candy[i]+1);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += candy[i];
        }
        return res;
    }
};