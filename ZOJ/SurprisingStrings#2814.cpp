#include <cstdio>
#include <cstring>

using namespace std;

const int MAXLINE = 128;

char str[MAXLINE];
int len;
int char2int(char c1, char c2) {
    return 32*(c1 - 'A') + (c2 - 'A');
}

bool check() {
    for(int k = 1; k <= len - 1; k++) {
        int table[32*32] = {};
        for(int i = 0; i < len - k; i++) {
            int j = i + k;
            int index = char2int(str[i], str[j]);
            if(table[index]) return false;
            table[index] = 1;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    while(scanf("%s", str) != EOF) {
        len = strlen(str);
        if(len == 1 && str[0] == '*') break;
        printf("%s is ", str);
        if(!check()) printf("NOT ");
        printf("surprising.\n");
    }
    return 0;
}
