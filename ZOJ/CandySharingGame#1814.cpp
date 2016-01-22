#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
std::vector<int> candy;
std::vector<int> tmp;
int n;

bool all_same() {

    for(int i = 1; i < n; i++) {
        if(candy[i] != candy[0]) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &n) != EOF){
        if(!n) break;
        candy.resize(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &candy[i]);
        }
        tmp.resize(n);
        int rounds = 0;
        while(!all_same()) {
            for(int i = 0; i < n; i++) {
                tmp[i] = candy[i]/2;
            }
            for(int i = 0; i < n; i++) {
                candy[i] = candy[i]/2 + tmp[(i + n - 1)%n];
                if(candy[i]%2) candy[i]++;
            }
            rounds++;
        }
        printf("%d %d\n", rounds, candy[0]);
    }
    return 0;
}
