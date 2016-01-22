#include<iostream>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    for(int k = 0; k < t; k++){
        int tot = 0;
        cin >> tot;
        int d = 0, n = 0, p = 0, q = 0;
        q = tot/25;
        tot %= 25;
        d = tot/10;
        tot %= 10;
        n = tot/5;
        tot %= 5;
        p = tot;
        cout << k + 1 << ' ' << q << " QUARTER(S), " << d <<" DIME(S), "
             << n << " NICKEL(S), " << p << " PENNY(S)" <<endl;
    }
    return 0;
}
