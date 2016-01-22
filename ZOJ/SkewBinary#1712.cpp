#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // 2^(k+1)-1
    string s;
    while(cin >> s) {
        int len = s.length();
        if(len == 1 && s[0] == '0') break;
        long long sum = 0;
        for(long long j = len - 1; j >= 0; j--) {
            long long shift = len - 1 - j + 1;
            long long val = s[j] - '0';
            sum += val * (( 1 << shift) - 1);
        }
        cout << sum << endl;
    }
    return 0;
}
