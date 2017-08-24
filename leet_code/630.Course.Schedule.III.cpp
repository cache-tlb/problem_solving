class Solution {
public:
    struct Item {
        int dur, end;
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        if (!n) return 0;
        std::vector<Item> cs(n);
        for (int i = 0; i < n; i++) {
            cs[i].dur = courses[i][0];
            cs[i].end = courses[i][1];
        }
        std::sort(cs.begin(), cs.end(), [](const Item &a, const Item &b) {
            return (a.end < b.end) || (a.end == b.end && a.dur < b.dur);
        });
        int cur_t = 0;
        int cur_id = 0;
        int res = 0;
        std::map<std::pair<int,int>,int> mp;
        for (int i = 0; i < n; i++) {
            if (cur_t + cs[i].dur <= cs[i].end) {
                mp[std::make_pair<>(cs[i].dur, i)] = 1;
                res++;
                cur_t += cs[i].dur;
            } else {
                std::pair<int,int> p = mp.rbegin()->first;
                int max_d = p.first;
                if (cs[i].dur < max_d) {
                    cur_t = cur_t - max_d + cs[i].dur;
                    mp.erase(p);
                    mp[std::make_pair<>(cs[i].dur, i)] = 1;
                }
            }
        }
        return res;
    }
};