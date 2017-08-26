/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        std::vector<Interval> res;
        int id = -1;
        for (int i = 0; i < n; i++) {
            if (intervals[i].end >= newInterval.start) {
                id = i;
                break;
            } else {
                res.push_back(intervals[i]);
            }
        }
        if (id < 0) {
            res.push_back(newInterval);
        } else {
            int new_start = std::min(newInterval.start, intervals[id].start);
            int id2 = -1;
            for (int i = id; i < n; i++) {
                if (intervals[i].start <= newInterval.end) {
                    id2 = i;
                } else {
                    break;
                }
            }
            if (id2 < 0) {
                res.push_back(Interval(new_start, newInterval.end));
                id2 = id;
            } else {
                int new_end = std::max(newInterval.end, intervals[id2].end);
                res.push_back(Interval(new_start, new_end));
                id2 ++;
            }
            for (int i = id2; i < n; i++) {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};