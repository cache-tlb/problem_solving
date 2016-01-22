#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        int ip[4]={};
        cin >> s;
        for(int k = 0; k < 4; k++){
            int num = 0, p = 1;
            for(int i = 0; i < 8; i++){
                num += (s[k*8+7-i] - '0')*p;
                p *= 2;
            }
            ip[k] = num;
        }
        for(int i = 0; i < 4; i++){
            cout << ip[i];
            if(i == 3) cout << endl;
            else cout << '.';
        }
    }        
    return 0;
}
