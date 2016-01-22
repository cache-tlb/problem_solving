#include<iostream>
#include<string.h>
using namespace std;
const int MAX = 100 + 10;
int a[MAX][MAX] = {};
int vis[MAX*MAX] = {};
bool ok(int n)
{
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += a[i][i];
        sum2 += a[i][n - i - 1];
    }
    int s = sum1;
    if(sum2 != s) return false;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += a[i][j];
        }
        if(sum != s) return false;
    }
    for(int j = 0; j < n; j++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i][j];
        }
        if(sum != s) return false;
    }   
    return true;
}
int main()
{
    int n;
    while(cin >> n){
        if(n == 0) break;
        memset(vis,0,sizeof(vis));
        int flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
                if(vis[a[i][j]]) flag = 1;
                vis[a[i][j]] = 1;
            }
        }
        if(ok(n)&&!flag) cout << "Yes" <<endl;
        else cout << "No" << endl;
    }    
    return 0;
}
