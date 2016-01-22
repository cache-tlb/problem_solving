#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 1000005;
char s[MAXN] = {};

int main()
{
    while(scanf("%s", &s)){
        int n = strlen(s);
        if(n == 1 && s[0] == '.') break;
        int p = 0, q = 1, len = 1;
        while(q < n){
            p = 0;
            while(s[p]!=s[q] || n % q != 0){
                q++;
                if(q==n) break;
            }
            len = q;
            int ok = 1;
            for(int i = 0; i < n/len - 1; i++){
                while(p < len && s[p] == s[q]){
                    p++;
                    q++;
                }
                if(p != len){
                    ok = 0;
                    break;
                }
                p = 0;
            }
            if(!ok) continue;
        }
        printf("%d\n", n / len);
    }
    return 0;
}
