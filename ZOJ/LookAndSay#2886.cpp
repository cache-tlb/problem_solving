#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s ="";
        cin>>s;
        int pos = 0;
        int cnt = 1;
        char cur = s[pos];
        int len = s.length();
        pos ++;
        while(pos<len){
            //cur = s[pos];
            if(s[pos]==cur) cnt++;
            else {
                cout<<cnt;
                cout<<cur;
                cur = s[pos];
                cnt = 1;
            }    
            pos++;
        }
        cout<<cnt;
        cout<<cur;
        cout<<endl;
    }    
    return 0;
}    
