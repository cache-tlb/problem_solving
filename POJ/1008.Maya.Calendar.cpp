#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, int> haab_month;
std::vector<std::string> tzolkin_month;

void init() {
    std::string s1[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    std::string s2[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    for (int i = 0; i < 19; i++) {
        haab_month[s1[i]] = i;
    }
    for (int i = 0; i < 20; i++) {
        tzolkin_month.push_back(s2[i]);
    }
}

int main() {
    init();
    int n;
    std::cin >> n;
    std::cout << n << std::endl;
    double day_d;
    int day;
    int year;
    std::string month;
    for (int i = 0; i < n; i++) {
        std::cin >> day_d >> month >> year;
        day = (int)day_d;
        int month_int = haab_month[month];
        int s = 365*year + month_int*20 + day;
        int year2 = s / (13*20);
        int md = s % (13*20);
        int month2 = md % 20;
        int day2 = md % 13;
        std::cout << day2 + 1 << ' ' << tzolkin_month[month2] << ' ' << year2 << std::endl;
    }
    return 0;
}
