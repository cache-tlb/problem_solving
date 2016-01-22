#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MAXN = 1000 + 10;
int main()
{
    int m,n;
    map<string,int> ms;
    cin >> m >> n;
    string s;
    for(int i = 0; i < m; i++){
        cin >> s;
        int value;
        cin >> value;
        ms[s] = value;
    }
    map<string,int>::iterator it;
    for(int k = 0; k < n; k++){
        int ans = 0;
        while(cin >> s){
            if(s==".") break;
            it = ms.find(s);
            if(it != ms.end()) ans += it->second;
        }
        cout << ans << endl;
    }        
    return 0;
}
