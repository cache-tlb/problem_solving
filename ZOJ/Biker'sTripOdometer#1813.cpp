#include<iostream>
#include<iomanip>
#define pi 3.1415927
using namespace std;
int main()
{
    double d = 0.0, r = 0.0, t = 0.0;
    int n = 0;
    cout << setiosflags(ios::fixed) << setprecision(2);
    while(cin >> d >> r >> t){
        n++;
        if(r == 0.0) break;
        double dis = pi*d*r/12.0/5280.0;
        double v = dis*3600.0/t; 
        cout << "Trip #" << n << ": ";
        cout << dis << ' ' << v << endl;
    }    
    return 0;
}
