#include<iostream>
#include<iomanip>
using namespace std;
const int MAXN = 1000 + 10;
int main()
{
    cout << setiosflags(ios::fixed) << setprecision(3);
    int c;
    cin >> c;
    while(c--){
        int n;
        double a[MAXN] = {};
        cin >> n;
        double sum = 0.0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        double ave = sum/(double)n;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > ave) cnt++;
        }
        cout << (double)cnt*100.00/(double)n << '%' << endl;
    }        
    return 0;
}
