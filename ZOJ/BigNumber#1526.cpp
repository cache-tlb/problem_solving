#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    double x = 0.0;
    cin >> n;
    while(n--){
        cin >> x;
        double tot = 0.0;
        //cout << "x =" << x <<endl; 
        for(double i = 1.0; i <= x; i += 1.0){
            tot += log10(i);
        }
        cout << (int)tot + 1 << endl;    
    }    
    return 0;
}
