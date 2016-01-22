#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a=0,p=0,first=1;
        cin>>a;
        while(a){
            if(a%2){
                if(first) first = 0;
                else cout<<' ';
                cout<<p;
            }
            a /= 2;
            p++;
        }
        cout<<endl;
    }            
    return 0;
}    
