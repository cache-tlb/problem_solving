#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const string str_high = "too high";
const string str_low = "too low";
const string str_eq = "right on";
const int MAXN = 12;

char buf[1024];

int main(int argc, char const *argv[])
{
    int guess;
    while(scanf("%d", &guess) != EOF) {
        if(!guess) break;
        vector<int> high, low;
        int res;
        gets(buf);
        while(strcmp(buf, str_eq.c_str())) {
            if(strcmp(buf, str_high.c_str()) == 0) {
                high.push_back(guess);
            }
            else if(strcmp(buf, str_low.c_str()) == 0) {
                low.push_back(guess);
            }
            scanf("%d", &guess);
            gets(buf);
        }
        res = guess;
        bool ok = true;
        for(int i = 0; i < high.size(); i++) {
            if(high[i] <= res){
                ok = false;
                break;
            }
        }
        for(int i = 0; i < low.size(); i++) {
            if(low[i] >= res) {
                ok = false;
                break;
            }
        }
        if(ok) printf("Stan may be honest\n");
        else printf("Stan is dishonest\n");
    }
    return 0;
}
