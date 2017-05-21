#include <string>
#include <cstdio>
#include <cctype>
#include <algorithm> 

using namespace std;

// trim from start
inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

int type(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 2;
    case '.':
        return 3;
    case 'e':
    case 'E':
        return 4;
    }
    return 0;
}

class Solution {
public:
    bool isNumber(string s) {
        s = trim(s);
        if (s.length() == 0) return false;
        for (int i = 0; i < s.length(); i++) {
            if (type(s[i]) == 0) return false;
        }
        int cur = 0;
        // check +-
        int t = type(s[cur]);
        if (t == 1) {
            cur++;
            t = type(s[cur]);
            if (t == 1 || t == 4) return false;
        } else if (t == 4) return false;
        // chech 0~9.0~9
        int end = s.length();
        for (int i = cur; i < s.length(); i++) {
            t = type(s[i]);
            if (t == 4) {
                end = i;
                break;
            } else if (t == 1) return false;
        }
        int cnt = 0;
        for (int i = cur; i < end; i++) {
            if (type(s[i]) == 3) cnt++;
        }
        if (cnt >= 2) return false;
        if (cnt > 0 && end - cur < 2) return false;
        if (end == s.length() - 1)  return false;
        cur = end + 1;
        if (cur >= s.length()) return true;

        t = type(s[cur]);
        if (t == 1) {
            cur++;
            t = type(s[cur]);
            if (t == 1 || t == 4) return false;
        } else if (t == 4) return false;
        if (cur == s.length()) return false;
        cnt = 0;
        for (int i = cur; i < s.length(); i++) {
            t = type(s[i]);
            if (t == 3) cnt++;
            else if (t != 2) return false;
        }
        if (cnt >= 2) return false;
        if (cnt > 0 && end - cur < 2) return false;
        return true;
    }
};