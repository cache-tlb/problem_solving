#include<iostream>
#include<string>
using namespace std;

const int MAX = 10+10;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,n;
        string s1="",s2="";
        string temp;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>temp;
            s1+=temp[0];
        }
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>temp;
            s2+=temp[0];
        }
        if(s1==s2) cout<<"SAME"<<endl;
        else cout<<"DIFFERENT"<<endl;
    }    
    return 0;
}
