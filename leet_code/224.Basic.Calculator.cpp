class Solution {
public:
    int calculate(string s) {
        trim(s);
        int res, end;
        parseAll(1, 0, end, res);
        std::cout << res << std::endl;
        return res;
    }
private:
    void trim(const std::string &s) {
        str = "";
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (s[i] == ' ') continue;
            str.push_back(s[i]);
        }
    }
    bool parseNum(int mul, int start, int &end, int &res) {
        end = start;
        res = 0;
        if (end < str.length() && str[end] >= '0' && str[end] <= '9') {
            while (end < str.length() && str[end] >= '0' && str[end] <= '9') {
                res = res*10 + (str[end] - '0');
                end ++;                
            }
            res *= mul;
            return true;
        }
        return false;
    }
    bool parseOp(int start, int &end, bool &is_add) {
        end = start;
        if (end < str.length() && (str[end] == '+' || str[end] == '-')) {
            char ch = str[end++];
            is_add = ch == '+';
            return true;
        }
        return false;
    }
    bool parseExpression(int mul, int start, int &end, int &res)
    {
        end = start;
        res = 0;
        if (end >= str.length()) return false;
        char ch = str[end];
        if (ch == '(') {
            int temp_res = 0;
            parseAll(1, start+1, end, res);
            if (str[end] != ')') {
                end = start;
                return false;
            }
            end++;
            res *= mul;
            return true;
        }
        return false;
    }
    bool parseAll(int mul, int start, int &end, int &res)
    {
        end = start;
        res = 0;
        if (parseNum(mul, start, end, res) || parseExpression(mul, start, end, res))
        {
            bool is_add = false;
            start = end;
            bool has_op = parseOp(start, end, is_add);
            if (has_op)
            {
                start = end;
                int res2 = 0;
                bool ok = parseAll(is_add ? 1 : -1, start, end, res2);
                res = res + res2;
            }
            return true;
        }
        return false;
    }
    std::string str;
};
