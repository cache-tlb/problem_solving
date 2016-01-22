#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int p=0,a=0;
        cin>>a;
        while(!(a%2)){
            p++;
            a /= 2;
        }
        cout<<a<<' '<<p<<endl;
    }    
    return 0;
}    
