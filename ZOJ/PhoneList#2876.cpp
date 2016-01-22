#include<iostream>
#include<string>
using namespace std;
const int MAX = 10000 + 10;
void sort1(string array[], int zz,int yy)
{
     int z,y;
     string k;
     if(zz<yy)
     {
         z=zz;y=yy;k=array[z];
         do{
           while(z<y&&array[y]>=k)y--;
             if(z<y)
             {
                 array[z]=array[y];
                 z++;   
             }       
           while(z<y&&array[z]<=k)z++;
           if(z<y)
             array[y]=array[z];               
         }while(z!=y);
         array[z]=k;
         sort1(array,zz,z-1);
         sort1(array,z+1,yy);    
     }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s[MAX];
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        sort1(s, 0, n - 1);
        int flag = 0;
        for(int i = 1; i < n; i++){
            if(s[i].length() >= s[i - 1].length()){
                int k = 0;
                while(k < s[i - 1].length()){
                    if(s[i - 1][k] != s[i][k]) break;
                    k++;
                }
                if(k == s[i - 1].length()) flag = 1;
            }
            if(flag == 1) break;
        }
        if(flag) cout << "NO" << endl;
        else cout << "YES" <<endl;
    }
    return 0;
}
