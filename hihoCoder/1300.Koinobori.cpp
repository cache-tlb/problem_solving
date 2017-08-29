#include <iostream>
#include <vector>
#include <list>

std::string str;
std::vector<int> match;
std::vector<int> left_sibling_size;
int n;

long long find(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (str[i] == ')' || left_sibling_size[i] >= 0) continue;
        int tmp = 0, s = i;
        while (s <= end && str[s] == '(') {
            left_sibling_size[s] = tmp;
            s = match[s] + 1;
            tmp++;
        }
    }
    long long res = 0;
    for (int i = start; i <= end; i++) {
        if (str[i] == ')') continue;
        res += (left_sibling_size[i] + 1);
    }
    return res;
}

long long solve() {
    long long res = 0;
    n = str.length();
    match.clear();
    match.resize(n, -1);
    left_sibling_size.clear();
    left_sibling_size.resize(n, -1);
    std::list<int> left_pos;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') left_pos.push_back(i);
        else if (str[i] == ')' && !left_pos.empty()) {
            int p = left_pos.back();
            left_pos.pop_back();
            match[p] = i;
            match[i] = p;
        }
    }
    for (int i = 0; i < n; i++) {
        if (match[i] < 0) continue;
        int start = i, end = i + 1;
        while (end < n && match[end] >= 0) end++;
        res += find(start, end - 1);
        i = end;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == ')') str.push_back(s[i]);
    }
    long long res = solve();
    std::cout << res << std::endl;
    return 0;
}
