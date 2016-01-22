#include<iostream>
using namespace std;
const int MAXN = 1000 + 10;
int main()
{
    int t;
    cin >> t;
    int first = 1;
    while(t--){
        if(first) first = 0;
        else cout << endl;
        int n;
        cin >> n;
        int a[MAXN] = {}, b[MAXN] = {};
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 1;
        b[0] = 1;
        for(int i = 1; i < n; i++){
            int temp = 0;
            for(int j = 0; j < i; j++){
                if(a[i] > a[j] && b[j] > temp){
                    temp = b[j];
                }
            }
            b[i] = temp + 1;
        }
        //for(int i = 0; i < n; i++){
        //    cout << b[i] << ' ';
        //}
        for(int i = 0; i < n; i++){
            if(ans < b[i]) ans = b[i];
        }    
        cout << ans << endl;
    }
    return 0;
}
