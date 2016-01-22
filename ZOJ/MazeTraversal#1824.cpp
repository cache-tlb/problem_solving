#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
const int MAX = 60 + 10;
char direct[]={'N','E','S','W'};
int main()
{
    int m,n;
    string a[MAX];
    while(cin >> m >> n){
        int toward = 0;
        getchar();
        for(int i = 0; i < m; i++){
            getline(cin,a[i]);
        }
        int x, y;
        cin >> x >> y;
        x--;y--;
        char cmd;
        while(scanf("%c",&cmd)){
            if(cmd=='Q') break;
            else if(cmd == 'R') toward = (toward+1)%4;
            else if(cmd == 'L') toward = (toward+3)%4;
            else if(cmd == 'F'){
                if(toward == 0){
                    if(x>0&&a[x-1][y]!='*') x--;
                }
                else if(toward == 1){
                    if(y<n-1&&a[x][y+1]!='*') y++;
                }
                else if(toward == 2){
                    if(x<m-1&&a[x+1][y]!='*') x++;
                }
                else if(toward == 3){
                    if(y>0&&a[x][y-1]!='*') y--;
                }
            }
        }
        cout << x + 1 << ' ' << y + 1 << ' ' << direct[toward] << endl;
    }    
    return 0;
}
