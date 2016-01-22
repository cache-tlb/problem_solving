#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int str2int(string &s){
    int ret = s[0] - '0';
    switch(s[1]){
    case 'p':
        break;
    case 's':
        ret += 10;
        break;
    case 'm':
        ret += 20;
        break;
    case 'z':
        ret += 30;
        break;
    default:
        break;
    }
    return ret;
}

int a[40] = {};

bool check7pairs(){
    for(int i = 0; i < 40; i++){
        if(a[i]%2) return false;
        if(a[i]>2) return false;
    }
    return true;
}

int ind[] = {1,9,11,19,21,29,31,32,33,34,35,36,37};
bool check13orphans(){
    int tot = 0;
    for(int i = 0; i < 13; i++){
        tot += a[ind[i]];
        if(!a[ind[i]]) return false;
    }
    if(tot != 14) return false;
    return true;
}

void preprocess(string &str){
    memset(a, 0, sizeof(a));
    for(int i = 0; i < 14; i++){
        string sub = str.substr(i*2, 2);
        int v = str2int(sub);
        a[v]++;
    }
}

int main(int argc, char const *argv[])
{
    string str;
    while(cin>>str){
        if(str.length()!=14*2){
            printf("Neither!\n");
            continue;
        }
        preprocess(str);
        if(check7pairs()){
            printf("Seven Pairs\n");
        }
        else if(check13orphans()){
            printf("Thirteen Orphans\n");
        }
        else{
            printf("Neither!\n");
        }
    }
    return 0;
}
