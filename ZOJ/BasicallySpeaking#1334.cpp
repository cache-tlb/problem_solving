#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int NDIGIT = 7;
char maps[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

char line[16];
int res[64];
int nres;

int main(int argc, char const *argv[]) {
    int bf, bt;
    while(scanf("%s%d%d", line, &bf, &bt) != EOF){
        int len = strlen(line);
        int sum = 0, p = 1;
        for(int i = len-1; i >= 0; i--){
            int num = 0;
            if('0' <= line[i] && line[i] <= '9' ) num = line[i] - '0';
            else if('A' <= line[i] && line[i] <= 'F') num = line[i] - 'A' + 10;
            sum += p*num;
            p *= bf;
        }
        memset(res, 0, sizeof(res));
        nres = 0;
        while(sum){
            res[nres++] = sum % bt;
            sum /= bt;
        }
        if(nres > NDIGIT){
            printf("  ERROR\n");
        }
        else{
            for(int i = 0; i + nres < NDIGIT; i++) printf(" ");
            for(int i = nres - 1; i >= 0; i--) printf("%c", maps[res[i]]);
            printf("\n");
        }
    }
    return 0;
}
