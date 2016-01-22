/*#include<iostream>
#include<stdio.h>
#include<sstream>
#include<string>
using namespace std;
const int CAPASITY = 200;
const int MAXN = 100 + 10;
const int MAXCOST = 2000;
int main()
{
    string str;
    int totdis;
    while(cin >> totdis){
        int n = 1;
        int flag = 1;
        int a[MAXN][CAPASITY + 1] = {}, cost[MAXN] = {}, dis[MAXN] = {};
        getchar();
        while(getline(cin, str)){
            if(str=="") break;
            stringstream stream;
            stream << str;
            stream >> dis[n];
            stream >> cost[n];
            n++;
        }
        //cout << "n = "<< n <<endl;
        if(totdis - dis[n-1] > 100) flag = 0;
        if(dis[1] > 100 && totdis > 100) flag = 0;
        for(int i = 2; i < n; i++){
            if(dis[i] - dis[i-1] > CAPASITY){
                flag = 0;
                break;
            }    
        }
        if(flag == 0){
            cout << "Impossible" << endl;
            continue;
        }
        //for(int i = 1; i < n; i++){
        //    cout << dis[i] << ' ' << cost[i] << endl;
        //}    
        for(int i = 0; i <= CAPASITY; i++){
            a[0][i] = 0;
        }
        for(int i = 0; i <= CAPASITY; i++){
            if(i + dis[1] < 100) continue;
            a[1][i] = (i - 100 + dis[1])*cost[1];
        }
        for(int i = 2; i < n; i++){
            for(int j = 0; j <= CAPASITY; j++){
                int d = dis[i] - dis[i-1];
                int minimum = CAPASITY*MAXCOST*MAXN;
                for(int k = d; k <= CAPASITY; k++){
                    if(j + d < k) break;
                    int temp = cost[i]*(j-k+d) + a[i-1][k];
                    if(temp < minimum) minimum = temp;
                }
                a[i][j] = minimum;
            }
        }
        //for(int i = 0; i < n; i++){
        //    printf("a[%d][%d]=%d a[%d][%d]=%d a[%d][%d]=%d a[%d][%d]=%d\n",i,50,a[i][50],i,100,a[i][100],i,150,a[i][150],i,200,a[i][200]);
        //}
        cout << a[n-1][totdis-dis[n-1]+100] << endl;
    }    
    return 0;
}
*/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int dp[101][201];//加油站坐标，剩余油量
int d[101];//gas station distance
int p[101];//price

int main()
{
//freopen("debug\\in.txt","r",stdin);
    int total,top,num;
    int i,j,k;
    string s;
    char ch;
    int MAX=100000000;
    int t;
    cin >> t;
    while(t--){
        cin>>total;
        getchar();
        top=0;
        while(getline(cin,s)){
            if(s=="") break;
            num=0;
            for(i=0;i<s.size();i++){
                if(s[i]==' ') break;
                num=num*10+s[i]-'0';
            }
            d[top]=num;
            num=0;
            for(i=i+1;i<s.size();i++) num=num*10+s[i]-'0';
            p[top]=num;
            top++;
        }
        d[top]=total;//终点站，这个不是加油站了
        p[top]=MAX;
        top++;
        
        for(i=0;i<top;i++){
            for(j=0;j<=200;j++){
                dp[i][j]=MAX;
            }
        }
        dp[0][100-d[0]]=0;
        for(i=0;i<top-1;i++){
            for(j=0;j<=200;j++){
                if(dp[i][j]!=MAX){
                    for(k=0;k<=200;k++){
                        if(j+k>200) break;//加油超过200了
                        if(j+k-(d[i+1]-d[i])<0) continue;//到下一个加油站需要的油量不够
                        dp[i+1][j+k-(d[i+1]-d[i])]=min(dp[i+1][j+k-(d[i+1]-d[i])],dp[i][j]+k*p[i]);
                    }
                }
            }
        }
        int mn=MAX;
        for(i=100;i<=200;i++) mn=min(dp[top-1][i],mn);
        if(mn!=MAX) cout<<mn<<endl;
        else cout<<"Impossible"<<endl;
        if(t) cout << endl;
    }
    return 0;
}
