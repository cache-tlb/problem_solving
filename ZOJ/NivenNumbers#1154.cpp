#include <iostream>
#include <cstdio>
using namespace std;

int b, n;
char buf[1024];
string str;

int sum, val;
void calc() {
    sum = 0;
    val = 0;
    for(int i = 0; i < str.length(); i++) {
        sum += str[i] - '0';
        val = val * b + str[i] - '0';
    }
}

bool process() {
    calc();
    //cout << sum << ' ' << val << endl;
    return (val % sum == 0);
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T--){
        while(scanf("%d", &b) != EOF){
            if(!b) break;
            scanf("%s", buf);
            str = buf;
            if(process()) printf("yes\n");
            else printf("no\n");
        }
        if(T) printf("\n");
    }
    return 0;
}
