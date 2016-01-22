#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--){
        string s;
        getline(cin,s);
        int len=s.length();
        for(int i=0;i<len;i++){
            cout<<s[len-i-1];
        }
        cout<<endl;
    }    
    return 0;
}    
