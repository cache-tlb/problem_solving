#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,t;
    while(cin >> s >> t){
        int p = 0, q = 0;
        int ls = s.length(), lt = t.length();
        while(p < ls && q < lt){
            if(s[p] == t[q]){
                p++;
                q++;
            }
            else q++;
        }
        if(p==ls) cout << "Yes" << endl;
        else cout << "No" << endl;
    }            
    return 0;
}
