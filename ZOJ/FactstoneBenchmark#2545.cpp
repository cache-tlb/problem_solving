#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int year;
    while(cin >> year){
        if(year==0) break;
        year -= 1960;
        int nbit = 4;
        while(year >= 10){
            nbit *= 2;
            year -= 10;
        }
        //cout << nbit <<endl;
        int F = 1;
        double sum = 0.0;
        while(sum <= log10(2.0)*(double)nbit){
            F++;
            sum += log10(double(F));
        }
        cout << F - 1 << endl;
    }    
    return 0;
}
