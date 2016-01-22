#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 1000;
char a[MAX], b[MAX];
int la,lb;

void convert(char s[],int pa,int pb,int ps,string cmd){
    //cout << "-------------------------" <<endl;
    //cout << "stack is: " << s <<endl;
    //cout << "pa = " << pa << endl << "pb = " << pb << endl << "ps = " << ps << endl; 
    if((pa == la) && (pb == lb) && (ps == 0)){
        cout << cmd <<endl;
        return;
    }
    char ss[MAX];
    if(pa < la){
        s[ps] = a[pa];
        s[ps + 1] = '\0';
        string cc = cmd + "i ";
        strcpy(ss,s);
        convert(ss, pa +1, pb, ps + 1, cc);
    }    
    if(s[ps - 1] == b[pb]){
        strcpy(ss,s);
        ss[ps - 1] = '\0';
        string cc = cmd + "o ";
        convert(ss, pa, pb + 1, ps - 1,cc);
    }
}
int main()
{
    while(cin >> a >> b){
        la = strlen(a);
        lb = strlen(b);
        char s[MAX];
        string cmd = "";
        cout<< '[' << endl;
        convert(s, 0, 0, 0,cmd);
        cout<< ']' << endl;
    }    
    return 0;
}
