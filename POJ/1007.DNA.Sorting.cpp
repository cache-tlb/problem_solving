#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Item {
    std::string str;
    int value;
    int index;
    Item(std::string &s, int v, int i) : str(s), value(v), index(i) {}
};

bool cmp (const Item &a, const Item &b) {
    return (a.value < b.value) || (a.value == b.value && a.index < b.index);
}

int compute_score(std::string &s) {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (s[i] > s[j]) ans ++;        
        }
    }
    return ans;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::vector<Item> v;
    for (int i = 0; i < m; i++) {
        std::cin >> s;
        v.push_back(Item(s, compute_score(s), i));
    }
    std::sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < m; i++) {
        std::cout << v[i].str << std::endl;
    }
    return 0;
}
