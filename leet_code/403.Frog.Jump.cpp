class Solution {
public:
    struct Item {
        int id, step;
        Item() {}
        Item(int i, int s) : id(i), step(s) {}
    };
    std::map<int,int> dis2stone;
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            dis2stone[stones[i]] = i;
        }
        std::vector<std::map<int,int> > table;
        table.resize(n+1);
        std::list<Item> q;
        q.push_back(Item(0, 0));
        table[0][0] = 1;
        while (!q.empty()) {
            Item item = q.front();
            q.pop_front();
            int id = item.id, last_step = item.step;
            // std::cout << id << ' ' << last_step<< std::endl;
            int pos = stones[id];
            for (int d = -1; d <= 1; d++) {
                int new_step = d + last_step;
                if (new_step <= 0) continue;
                if (dis2stone.count(new_step+pos) == 0) continue;
                int new_id = dis2stone[new_step+pos];
                if (new_id == n-1) return true;
                Item new_item = Item(new_id, new_step);
                if (table[new_id].count(new_step) > 0) continue;
                q.push_back(new_item);
                table[new_id][new_step] = 1;
            }
        }
        return false;
    }
};