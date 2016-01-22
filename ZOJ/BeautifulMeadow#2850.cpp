#include<iostream>
#include<string.h>
using namespace std;
const int MAX = 10 + 10;
int m = 0, n = 0;
int a[MAX][MAX] = { };
void work()
{
    int flag1 = 0, flag2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0) flag1 = 1;
        }
    }
    if(!flag1){
        cout << "No" <<endl;
        return;
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if((a[i][j] == 0) && (i < n - 1)){
                if(a[i + 1][j] == 0){
                    flag2 = 1;
                }
            }
            if((a[i][j] == 0) && (j < m - 1)){
                if(a[i][j + 1] == 0){
                    flag2 = 1;
                }
            }        
        }
    }
    if(flag2) cout << "No" << endl;
    else cout << "Yes" << endl;                
}
int main()
{
    while(cin >> n >> m){
        if(!n && !m) break;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        work();
    }    
    return 0;
}
