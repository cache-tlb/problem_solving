#include <iostream>
#include <string>

int cmp(char x, char y) {
    if (x == 'R' && y == 'S') return 1;
    if (x == 'P' && y == 'R') return 1;
    if (x == 'S' && y == 'P') return 1;
    if (x == y) return 0;
    return -1;
}

int main() {
    std::string s1, s2;
    while (std::cin >> s1 >> s2) {
        if (s1 == "E") break;
        int n = s1.length();
        int p1 = 0, p2 = 0;
        for (int i = 0; i < n; i++) {
            int res = cmp(s1[i], s2[i]);
            if (res == 1) p1++;
            else if (res == -1) p2++;
        }
        std::cout << "P1: " << p1 << "\nP2: " << p2 << "\n";
    }
    return 0;
}
