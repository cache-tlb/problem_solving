#include<iostream>
using namespace std;
const int H = 168;
int main()
{
    int a[2];
    cin >> a[0] >> a[1] >> a[2];
    int flag = 0;
    int ans = 0;
    for(int i = 0; i < 3; i++){
        if(a[i] <= H){
            ans = a[i];
            flag = 1;
            break;
        }
    }
    if(flag) cout << "CRASH " << ans << endl;
    else cout << "NO CRASH" << endl;         
    return 0;
}
