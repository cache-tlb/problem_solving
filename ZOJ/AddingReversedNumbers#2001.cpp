#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

long long reverse(long long x){
    long long res = 0;
    while(x){
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        long long c = reverse(a) + reverse(b);
        while(c % 10 == 0){
            c /= 10;
        }
        cout << reverse(c) << endl;
    }
    return 0;
}
