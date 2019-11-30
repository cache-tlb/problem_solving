class Solution {
public:
    string countOfAtoms(string formula) {
        str = formula;
        int end;
        std::map<std::string,int> res;
        tryParse(0, end, res);
        std::ostringstream oss;
        for (std::map<std::string,int>::iterator it = res.begin(); it != res.end(); it++)
        {
            // std::cout << it->first << ' ' << it->second << std::endl;
            if (it->second >= 2)
                oss << it->first << it->second;
            else if (it->second == 1)
                oss << it->first;
        }
        return oss.str();
    }
private:
    bool parseNum(int start, int &end, int &res)
    {
        end = start;
        if (start < str.length() && str[start] >= '0' && str[start] <= '9')
        {
            res = 0;
            while (start < str.length() && str[start] >= '0' && str[start] <= '9')
            {
                res = res*10 + (str[start] - '0');
                start++;
            }
            end = start;
            return true;
        }
        return false;
    }
    void mergeRes(std::map<std::string,int> &res, std::map<std::string,int> &res2, int count)
    {
        for (std::map<std::string,int>::iterator it = res2.begin(); it != res2.end(); it++)
        {
            res[it->first] += count*it->second;
        }
    }
    bool parseAtom(int start, int &end, std::string &atom, int &count)
    {
        char ch = str[start];
        atom = "";
        count = 0;
        end = start;
        if (ch >= 'A' && ch <= 'Z')
        {
            atom.push_back(ch);
            start++;
            while(start < str.length() && str[start] >= 'a' && str[start] <= 'z')
            {
                atom.push_back(str[start]);
                start ++;
            }
            end = start;
            bool has_num = parseNum(start, end, count);
            if (!has_num) count = 1;
            return true;
        }
        return false;
    }
    bool parseExpression(int start, int &end, std::map<std::string,int> &res, int &count)
    {
        char ch = str[start];
        res.clear();
        count = 0;
        if (ch == '(')
        {
            tryParse(start + 1, end, res);
            start = end;
            if (str[start] != ')')
            {
                res.clear();
                return false;
            }
            start += 1;
            bool has_num = parseNum(start, end, count);
            if (!has_num) count = 1;
            return true;
        }
        return false;
    }
    bool tryParse(int start, int &end, std::map<std::string,int> &res)
    {
        end = start;
        res.clear();
        std::map<std::string, int> temp_res;
        std::string atom;
        int count = 0;
        if (parseAtom(start, end, atom, count))
        {
            // std::cout << atom << ' ' << count << std::endl;
            temp_res[atom] = count;
            start = end;
            tryParse(start, end, res);
            mergeRes(res, temp_res, 1);
            return true;
        }
        else if (parseExpression(start, end, temp_res, count))
        {
            start = end;
            tryParse(start, end, res);
            mergeRes(res, temp_res, count);
            return true;
        }
        return false;
    }
    std::string str;
};
