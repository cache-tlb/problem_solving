#include<iostream>
#include<string>
using namespace std;

const int MAX = 100 + 10;
struct DNA{
    string str;
    int cnt;
};

bool operator >(const DNA &a,const DNA &b){
    return a.cnt > b.cnt;
}    
bool operator <(const DNA &a,const DNA &b){
    return a.cnt < b.cnt;
}  
void sort1(DNA a[], int m)
{
     for(int cur = 0; cur < m - 1; cur++){
         int minpos = cur;
         for(int i = cur; i < m; i++){
             if(a[i] < a[minpos]) minpos = i;
         }
         DNA temp = a[minpos];
         for(int i = minpos; i >= cur+1; i--){
             a[i] = a[i - 1];
         }
         a[cur] = temp;
     }            
}

int main()
{
    DNA s[MAX];
    int n, m;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int k = 0; k < m; k++){
            cin >> s[k].str;
            s[k].cnt = 0;
            int l = s[k].str.length();
            for(int i = 0;  i < l - 1; i++){
                for(int j = i + 1; j < l; j++){
                    if(s[k].str[i] > s[k].str[j]) s[k].cnt ++;
                }
            }
        }
        sort1(s, m);
        for(int i = 0; i < m; i++){
            cout << s[i].str <<endl;
        }
        if(t) cout << endl;
    }
    return 0;
}
