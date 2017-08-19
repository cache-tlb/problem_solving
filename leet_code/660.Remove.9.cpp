class Solution {
public:
    int newInteger(int n) {
        int res = 0;
        std::list<int> lst;
        while (n) {
            int q = n % 9;
            n /= 9;
            lst.push_back(q);
            // std::cout << q << std::endl;
        }
        while (!lst.empty()) {
            int x = lst.back();
            lst.pop_back();
            res = res*10 + x;
        }
        return res;
    }
};