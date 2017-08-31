class Solution {
public:
    class MediumRecorder {
    public:
        MediumRecorder() : size_A(0), size_B(0) {}
        int popA() {
            auto it = A.begin();
            int x = it->first;
            if (it->second <= 1) A.erase(it);
            else A[x]--;
            size_A--;
            return x;
        }
        int popB() {
            auto it = B.begin();
            int x = it->first;
            if (it->second <= 1) B.erase(it);
            else B[x]--;
            size_B--;
            return x;
        }
        void pushA(int x) {
            A[x]++;
            size_A++;
        }
        void pushB(int x) {
            B[x]++;
            size_B++;
        }
        void eraseA(int x) {
            A[x]--;
            if (A[x] <= 0) A.erase(x);
            size_A--;
        }
        void eraseB(int x) {
            B[x]--;
            if (B[x] <= 0) B.erase(x);
            size_B--;
        }
        void insert(int x) {
            if (size_A == size_B) {
                pushB(x);
                int y = popB();
                pushA(y);
            } else {
                pushA(x);
                int y = popA();
                pushB(y);
            }
        }
        void remove(int x) {
            if (size_A == size_B) {
                int min_B = B.begin()->first;
                if (x >= min_B) {
                    eraseB(x);
                } else {
                    eraseA(x);
                    int y = popB();
                    pushA(y);
                }
            } else {
                int max_A = A.begin()->first;
                if (x <= max_A) {
                    eraseA(x);
                } else {
                    eraseB(x);
                    int y = popA();
                    pushB(y);
                }
            }
        }
        double query() const {
            if (size_A == size_B) {
                int x = A.begin()->first, y = B.begin()->first;
                return (double(x)+double(y))/2.0;
            } else return double(A.begin()->first);
        }
        // size of A >= size of B
        std::map<int,int,std::greater<int> > A;   // smaller part
        std::map<int,int,std::less<int> > B;      // larger part
        int size_A, size_B;
    };
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        std::vector<double> res;
        int n = nums.size();
        if (n < k) return res;
        res.reserve(n-k+1);
        MediumRecorder recoder;
        for (int i = 0; i < k; i++) {
            recoder.insert(nums[i]);
        }
        res.push_back(recoder.query());
        for (int i = k; i < n; i++) {
            recoder.insert(nums[i]);
            recoder.remove(nums[i-k]);
            res.push_back(recoder.query());
        }
        return res;
    }
};
