#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string str[15];

int main(int argc, char const *argv[])
{
    int t = 0;
    int n;
    while(cin >> n){
        if(!n) break;
        t++;
        for(int i = 0; i < n; i++) cin >> str[i];
        cout << "SET " << t << endl;
        int p = 0;
        for(; p < n; p += 2) cout << str[p] << endl;
        p = (n % 2) ? n - 2 : n - 1;
        for(; p >= 0; p -= 2) cout << str[p] << endl;
    }
    return 0;
}
