#include<iostream>
#include<string>
using namespace std;
const int MAXN = 1000 + 10;
char c[] = {'Z','O','J','7'};
int main()
{
    string s;
    while(cin >> s){
        int a[4] = {};
        string t = "";
        int len = s.length();
        for(int i = 0; i < len; i++){
            switch(s[i]){
                case 'Z': a[0]++;break;
                case 'O': a[1]++;break;
                case 'J': a[2]++;break;
                case '7': a[3]++;break;
                default: t.push_back(s[i]);
            }
        }        
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < a[i]; ++j){
                cout << c[i];
            }
        }        
        cout << t << endl;
    }
    return 0;
}
