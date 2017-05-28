#include <queue>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if (small_part.empty()) {
            small_part.push(num);
            return;
        }
        if (small_part.size() == large_part.size()) {
            large_part.push(-num);
            int val = large_part.top();
            large_part.pop();
            small_part.push(-val);
        } else {
            small_part.push(num);
            int val = small_part.top();
            small_part.pop();
            large_part.push(-val);
        }
    }
    
    double findMedian() {
        if (small_part.empty()) return 0;
        if (small_part.size() == large_part.size()) {
            return(small_part.top() + -1*large_part.top()) / 2.0;
        }
        return small_part.top();
    }
    std::priority_queue<int> small_part, large_part;
};
