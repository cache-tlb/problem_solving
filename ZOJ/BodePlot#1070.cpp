#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    double VS = 0.0, R = 0.0, C = 0.0, w = 0.0;
    int n = 0;
    cout << setiosflags(ios::fixed) << setprecision(3);
    cin >> VS >> R >> C >> n;
    while(n--){
        cin >> w;
        cout << VS*R*w*C/sqrt(1+w*w*C*C*R*R) << endl;
    }    
    return 0;
}
