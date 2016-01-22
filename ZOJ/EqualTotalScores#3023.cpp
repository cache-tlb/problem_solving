#include<iostream>
using namespace std;
const int MAX = 100;
int main()
{
    int n, m;
    while(cin >> n >> m){
        if((!n)&&(!m)) break;
        int a[MAX] = {}, b[MAX] = {},c[MAX];
        int sa = 0, sb = 0;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            a[temp] = 1;
            sa += temp;
        }
        for(int i = 0; i < m ;i++){
            int temp;
            cin >> temp;
            b[temp] = 1;
            sb += temp;
        }
        int d = sa - sb;
        int ans1 = 0, ans2 = 0, flag = 0;
        //cout << d <<endl;
        if(d%2) flag = 0;
        else{
            if(d >= 0){
                for(int i = 0; i < MAX; i++){
                    if(i >= d/2 && a[i] && b[i-d/2]){
                        ans1 = i;
                        ans2 = i - d/2;
                        flag = 1;
                        //cout << "a "<<i <<endl;
                        break;
                    }
                }
            }
            else{
                for(int i = 0; i < MAX; i++){
                    if(a[i] && b[i-d/2]){
                        ans1 = i;
                        ans2 = i - d/2;
                        flag = 1;
                        //cout << "b "<<i << endl;
                        break;
                    }
                }
            }
        }
        if(flag) cout << ans1 << ' ' << ans2 << endl;
        else cout << -1 << endl;
    }        
    return 0;
}
