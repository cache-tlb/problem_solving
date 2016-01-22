#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0, temp = 0;
        for(int i = 0; i < n; i++){
            cin >> temp;
            ans += (temp - 1);
        }
        cout << ans + 1 << endl;
    }        
    return 0;
}
