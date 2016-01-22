#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const string up = "up";
const string down = "down";
const string even = "even";

string s1[3], s2[3], res[3];
int weight[12];
int N;
bool ok;
int flag = 0;
int which = 0;

void judge() {
    for(int i = 0; i < 3; i++){
        int sum1 = 0, sum2 = 0;
        for(int j = 0; j < s1[i].length(); j++){
            sum1 += weight[s1[i][j]-'A'];
            sum2 += weight[s2[i][j]-'A'];
        }
        if(sum1==sum2 && res[i]!=even) return;
        if(sum1<sum2 && res[i]!=down) return;
        if(sum1>sum2 && res[i]!=up) return;
    }
    ok = true;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        for(int i = 0; i < 3; i++){
            cin >> s1[i] >> s2[i] >> res[i];
        }
        ok = false;
        for(int i = 0; i < 12; i++){
            memset(weight, 0, sizeof(weight));
            for(int j = -1; j <= 1; j += 2){
                weight[i] = j;
                judge();
                if(ok){
                    flag = j;
                    which = i;
                    break;
                }
            }
            if(ok) break;
        }
        if(flag==1)
            printf("%c is the counterfeit coin and it is heavy.\n", which+'A');
        else
            printf("%c is the counterfeit coin and it is light.\n", which+'A');
    }
    return 0;
}
