#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

struct Sheet {
    int fl, fr, bl, br;
    Sheet():fl(-1),fr(-1),bl(-1),br(-1){}
};

int N;
char buf[1024];
string num2str(int num) {
    if(num <= N){
        sprintf(buf, "%d", num);
        return string(buf);
    }
    else{
        return string("Blank");
    }
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) != EOF){
        if(!N) break;
        printf("Printing order for %d pages:\n", N);
        int nsheet = (N+3)/4;
        vector<Sheet> vs;
        vs.resize(nsheet);
        int cnt = 1;
        for(int i = 0; i < nsheet; i++) {
            vs[i].fr = cnt++;
            vs[i].bl = cnt++;
        }
        for(int i = nsheet - 1; i >= 0; i--) {
            vs[i].br = cnt++;
            vs[i].fl = cnt++;
        }
        for(int i = 0; i < nsheet; i++) {
            if(vs[i].fr <= N || vs[i].fl <= N){
                printf("Sheet %d, front: %s, %s\n", i+1, num2str(vs[i].fl).c_str(), num2str(vs[i].fr).c_str());
            }
            if(vs[i].bl <= N || vs[i].br <= N){
                printf("Sheet %d, back : %s, %s\n", i+1, num2str(vs[i].bl).c_str(), num2str(vs[i].br).c_str());
            }
        }
    }
    return 0;
}
