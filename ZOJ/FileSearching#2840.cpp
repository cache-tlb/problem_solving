#include <cstdio>
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

const int MAXN = 128;

int N, M;
string dir[MAXN];

bool que_in_dic(const char *s, const char *t){
    int sl = strlen(s), tl = strlen(t), i, j, k = 0;
    for(i = 0; s[i] && s[i] != '*' && t[i]; i++, k++)
        if(s[i] != t[i]) break;
    if(s[i] != '*') return false;
    for(i = sl - 1, j = tl - 1; s[i] != '*' && j >= 0; i--, j--, k++)
        if(s[i] != t[j]) break;
    if(s[i] == '*' && k <= tl) return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    int first = 1;
    while(cin >> N){
        if(first) first = 0;
        else cout << endl;
        for(int i = 0; i < N; i++){
            cin >> dir[i];
        }
        cin >> M;
        string query;
        while(M--){
            cin >> query;
            int cnt = 0;
            for(int i = 0; i < N; i++){
                if(que_in_dic(query.c_str(), dir[i].c_str())){
                    cnt++;
                    if(cnt > 1){
                        cout << ", ";
                    }
                    cout << dir[i];
                }
            }
            if(!cnt){
                cout << "FILE NOT FOUND" << endl;
            }
            else{
                cout << endl;
            }
        }
    }
    return 0;
}
