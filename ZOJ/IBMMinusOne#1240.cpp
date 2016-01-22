#include<iostream>
#include<string>
using namespace std;

//const int MAX = 50+10;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        //char s[MAX]={};
        string s = "";
        cin>>s;
        int l = s.length();
        for(int j=0;j<l;j++){
            if(s[j]!='Z') s[j]++;
            else s[j] = 'A';
        }
        cout<<"String #"<<i+1<<endl<<s<<endl<<endl;
    }    
    return 0;
}
