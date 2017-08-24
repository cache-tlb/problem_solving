class Solution {
public:
    struct ProjItem {
        int prof, cap, id;
        ProjItem() {}
        ProjItem(int p, int c, int i) : prof(p), cap(c), id(i) {}
    };
    struct cmp {
        bool operator () (const ProjItem &a, const ProjItem &b) {
            return (a.prof > b.prof) || (a.prof == b.prof && a.cap < b.cap) || (a.cap == b.cap && a.prof == b.prof && a.id < b.id);
        }
    };
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        std::vector<ProjItem> projs(n);
        for (int i = 0; i < n; i++) {
            projs[i].prof = Profits[i];
            projs[i].cap = Capital[i];
            projs[i].id = i;
        }
        std::sort(projs.begin(), projs.end(), [](const ProjItem &a, const ProjItem &b){
            return (a.cap < b.cap) || (a.cap == b.cap && a.prof > b.prof) || (a.cap == b.cap && a.prof == b.prof && a.id < b.id);
        });
        std::map<ProjItem,int,cmp> current_set;
        int proj_id = 0;
        while (k--) {
            while (proj_id < n && projs[proj_id].cap <= W) current_set[projs[proj_id++]] = 1;
            if (current_set.empty()) break;
            ProjItem item = current_set.begin()->first;
            current_set.erase(item);
            W += item.prof;
        }
        return W;
    }
};