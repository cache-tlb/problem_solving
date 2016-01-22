#include<iostream>
#include<string>
using namespace std;
const int MAX = 10000 + 10;
const int MAXV = 250 + 10;
struct student{
    int v;
    string name;
};    
int main()
{
    int n;
    while(cin >> n){
        if(n==-1) break;
        int a, b, c;
        int ma = 0, mi = MAXV;
        int mai = 0, mii = 0;
        student s[MAX];
        for(int i = 0; i < n; i++){
            cin >> a >> b >> c;
            cin >> s[i].name;
            s[i].v = a*b*c;
            if(ma < s[i].v){
                ma = s[i].v;
                mai = i;
            }
            if(mi > s[i].v){
                mi = s[i].v;
                mii = i;
            }
        }
        cout << s[mai].name << " took clay from " << s[mii].name << '.' << endl;
    }
    return 0;
}
