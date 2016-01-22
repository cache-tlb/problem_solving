#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char dict[] = {'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};
char ans[256] = {};

int main(int argc, char const *argv[])
{
    string line;
    int state = 0;
    while(getline(cin, line)){
        if(line == "ENDOFINPUT") break;
        getline(cin, line);
        int n = line.length();
        for(int j = 0; j < n; j++){
            if('A' <= line[j] && line[j] <= 'Z')
                ans[j] = dict[line[j]-'A'];
            else
                ans[j] = line[j];
        }
        ans[n] = '\0';
        printf("%s\n", ans);
        getline(cin, line);
    }
    return 0;
}
