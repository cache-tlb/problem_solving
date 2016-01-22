#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXLEN = 1024;

int gcd(int x,int y)
{
    if(x % y == 0) return y;
    else return gcd(y, x % y);
}

char str1[MAXLEN], str2[MAXLEN];

int main(int argc, char const *argv[])
{
    while(scanf("%s", str1) != EOF) {
        if(!strcmp(str1, "-1")) break;
        scanf("%s", str2);
        int len1 = strlen(str1), len2 = strlen(str2);
        int match = 0;
        for(int offset = 0; offset < len2; offset++){
            int cnt = 0;
            for(int i = 0, j = offset; i < len1 && j < len2; i++, j++){
                if(str1[i]==str2[j]) cnt++;
            }
            match = max(match, cnt);
        }
        for(int offset = 0; offset < len1; offset++) {
            int cnt = 0;
            for(int i = offset, j = 0; i < len1 && j < len2; i++, j++) {
                if(str1[i]==str2[j]) cnt++;
            }
            match = max(match, cnt);
        }
        printf("appx(%s,%s) = ", str1, str2);
        if(!match) printf("0\n");
        else if(2*match == len1 + len2) printf("1\n");
        else{
            int div = gcd(2*match, len1 + len2);
            printf("%d/%d\n", 2*match/div, (len1 + len2)/div);
        }
    }
    return 0;
}
