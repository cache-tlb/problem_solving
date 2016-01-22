#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

const int MAXN = 64;
const int MAXM = 64;
set<string> dic;
string excuse[MAXM];
int n, m;

typedef pair<int,int> pii;

bool cmp (const pii &a, const pii &b){
    return (a.first > b.first) || (a.first == b.first && a.second < b.second);
}

int main(int argc, char const *argv[])
{
    string s;
    string word;
    int t = 0;
    while(cin >> n >> m){
        t++;
        dic.clear();

        for(int i = 0; i < n; i++){
            cin >> s;
            int len = s.length();
            for(int j = 0; j < len; j++){
                s[j] = tolower(s[j]);
            }
            dic.insert(s);
        }
        getchar();

        vector<pii> v;
        for(int i = 0; i < m; i++){
            getline(cin, s);
            //cout << s << endl;
            excuse[i] = s;
            int len = s.length();
            for(int j = 0; j < len; j++){
                if(isalpha(s[j])) s[j] = tolower(s[j]);
                else if(!isdigit(s[j])) s[j] = ' ';
            }
            istringstream is(s);
            int cnt = 0;
            while(is >> word){
                if(dic.count(word) != 0) cnt++;
            }
            v.push_back(pii(cnt, i));
        }
        sort(v.begin(), v.end() ,cmp);
        
        int occ = v[0].first;
        int k = 0;
        printf("Excuse Set #%d\n", t);
        while(v[k].first == occ) {
            printf("%s\n", excuse[v[k].second].c_str());
            k++;
        }
        printf("\n");
    }
    return 0;
}
