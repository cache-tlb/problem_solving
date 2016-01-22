#include<iostream>
#include<string>
using namespace std;

int root(int x){
    int ans = x;
    while(ans>=10){
        ans = ans/10 + ans%10;
    }    
    return ans;
}    
int main()
{
    string x = "" ;
    cin>>x;
    while(x!="0"){
        int l=x.length();
        int sum = 0;
        for(int i=0;i<l;i++){
            sum += x[i]-'0';
        }    
        cout<<root(sum)<<endl;
        cin>>x;
    }
    return 0;
}
