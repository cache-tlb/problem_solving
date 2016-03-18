#include <iostream>
#include <string>

int main() {
    std::string src;
    while (getline(std::cin, src)) {
        std::string dst;
        int n = src.length();
        int i = 0;
        while (i < n) {
            /*if (src[i] != 'y') {
                dst.push_back(src[i]);
                i++;
            }
            else {
                if (i + 2 < n && src[i+1]=='o'&&src[i+2]=='u') {
                    dst.push_back('w');
                    dst.push_back('e');
                    i += 3;
                } else {
                    dst.push_back(src[i]);
                    i++;
                }
            }*/
            bool ok = (i + 2 < n && src[i] == 'y' && src[i+1]=='o'&&src[i+2]=='u');
            if (ok) {
                dst.push_back('w');
                dst.push_back('e');
                i += 3;
            } else {
                dst.push_back(src[i]);
                i++;
            }
        }
        std::cout << dst << "\n";
    }
    return 0;
}
