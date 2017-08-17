class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        std::list<int> lst;
        std::vector<int> match_pos(n, -1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                lst.push_back(i); 
            } else {
                if (lst.empty()) {
                } else {
                    int match = lst.back();
                    lst.pop_back();
                    match_pos[match] = i;
                    match_pos[i] = match;
                }
            }
        }
        int res = 0;
        int seg = 0;
        for (int i = 0; i < n; i++) {
            if (match_pos[i] >= 0) {
                seg++;
                res = std::max(seg, res);
            } else seg = 0;
        }
        return res;
    }

};