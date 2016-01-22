#include<iostream>
#include<string.h>
using namespace std;
const int MAXN = 4+4;

int n = 0;
int city[MAXN][MAXN] = {};
int blanki[MAXN*MAXN] = {}, blankj[MAXN*MAXN] = {};
int walli[MAXN*MAXN] = {}, wallj[MAXN*MAXN] = {};
int Max = 0;
int nWall = 0;
int nBlank = 0;
bool valid(int cur){
    int i = blanki[cur], j = blankj[cur];
    int ii = 0, jj = 0;
    
    for(ii = i - 1; ii >=0 ; ii--){
        if(city[ii][j] != 0) break;
    }
    if(city[ii][j]==2) return false;
    
    for(jj = j - 1; jj >= 0; jj--){
        if(city[i][jj] !=0)break;
    }
    if(city[i][jj]==2) return false; 
       
    return true;
}
void work(int cur,int tot)
{
    if(cur>nBlank){
        if(tot>Max) Max = tot;
        return;
    }
        
    int i = blanki[cur], j = blankj[cur]; 
    city[i][j] = 0;
    work(cur+1,tot);
    city[i][j] = 2;
    if(valid(cur)){
        work(cur+1,tot+1);
    }
    city[i][j] = 0;
    return;
}
int main()
{
    cin>>n;    
    while(n!=0){
        memset(city,0,sizeof(city));
        memset(blanki,0,sizeof(blanki));
        memset(blankj,0,sizeof(blankj));
        memset(walli,0,sizeof(walli));
        memset(wallj,0,sizeof(wallj));
        Max = 0;
        nWall = 0;
        nBlank = 0;
        for(int i=0;i<n;i++){
            char temp[MAXN+10];
            cin>>temp;
            for(int j=0;j<n;j++){
                if(temp[j]!='.'){  //'.' indicating an open space 
                                   //and an uppercase 'X' indicating a wall
                    city[i][j] = 1;// 1 for wall,0 for blank,2 for machine gun.
                    walli[nWall] = i;
                    wallj[nWall] = j;
                    nWall++;
                }
                else{
                    nBlank++;
                    blanki[nBlank] = i;
                    blankj[nBlank] = j;
                }
            }
        }
        //cout<<nBlank<<endl;
        work(1,0);
        cout<<Max<<endl;
        cin>>n;
    }    
    return 0;
}
