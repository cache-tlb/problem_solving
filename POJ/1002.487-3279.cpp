#include <iostream>
#include <map>
#include <string>

int table[] = {
    '2','2','2', // A B C
    '3','3','3', // D E F
    '4','4','4', // G H I
    '5','5','5', // J K L
    '6','6','6', // M N O
    '7',' ','7','7', // P (Q) R S
    '8','8','8', // T U V
    '9','9','9', ' ' // W X Y (Z)
};

std::string process_str(const std::string &str) {
    std::string res;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '-' || str[i] == 'Q' || str[i] == 'Z') continue;
        if (str[i] >= '0' && str[i] <= '9') {
            res.push_back(str[i]);
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            res.push_back(table[str[i] - 'A']);
        }
        if (res.length() == 3) {
            res.push_back('-');
        }
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::map<std::string, int> m;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        m[process_str(s)] += 1;
    }
    bool flag = false;
    for (std::map<std::string, int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->second == 1) continue;
        std::cout << it->first << ' ' << it->second << std::endl;
        flag = true;
    }
    if (!flag) std::cout << "No duplicates." << std::endl;
    
    return 0;
}
