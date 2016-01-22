#include<iostream>
using namespace std;
const int MAX = 100*2 + 10 ;
int main()
{
    int temp = 0;
    while(cin >> temp){
        if(temp == -1) break;
        int has[MAX] = {}, num[MAX] = {};
        int n = 0;
        while(temp != 0){
            num[n] = temp;
            has[temp] = 1;
            n++;
            cin >> temp;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cur = num[i];
            if(has[2*cur]){
                ans++;
                //cout << cur << endl;
            }    
        }
        cout << ans <<endl;
    }            
    return 0;
}
