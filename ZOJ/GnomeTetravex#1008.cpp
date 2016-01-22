#include<iostream>
#include<map>
#include<string.h>
using namespace std;

const int MAX = 5 + 5;

struct square{
    int top, right, bottom, left;
};

int n = 0;
int flag = 0;
int nSet = 0;
square sq[MAX][MAX];
square sqset[MAX*MAX];
int sqnum[MAX*MAX];

bool valid(int i, int j)
{
    //int i = cur_pos/n, j = cur_pos%n;
    if(i > 0){
        if(sq[i][j].top != sq[i - 1][j].bottom) return false;
    }
    if(j > 0){
        if(sq[i][j].left != sq[i][j - 1].right) return false;
    }
    return true;        
}
void work(int cur_pos)
{
    if(cur_pos == n*n){
        flag = 1;
        return;
    }
    int i = cur_pos/n, j = cur_pos%n;
    for(int k = 0; k < nSet; k++){
        if(sqnum[k]==0) continue;
        sq[i][j] = sqset[k];
        if(valid(i, j)){
            sqnum[k]--;
            work(cur_pos + 1);
            sqnum[k]++;
        }
        if(flag) return;
    }
}
int main()
{
    int round = 0;
    while(cin >> n){
        flag = 0;
        nSet = 0;
        round++;
        if(n == 0) break;
        memset(sqnum, 0, sizeof(sqnum));
        for(int i = 0; i < n*n; i++){
            int top , right, bottom, left;
            cin >> top >> right >> bottom >> left;
            int ff = 0, pos = 0;
            for(int j = 0; j < nSet; j++){
                if((sqset[j].top == top) && (sqset[j].right == right) &&
                   (sqset[j].bottom == bottom) && (sqset[j].left == left)){
                       ff = 1;
                       pos = j;
                       break;
                }
            }
            if(ff){
                sqnum[pos]++;
            }
            else{
                sqset[nSet].top = top;
                sqset[nSet].right = right;
                sqset[nSet].bottom = bottom;
                sqset[nSet].left = left;
                sqnum[nSet] = 1;
                nSet++;
            }
        }
        
        work(0);
        if(round > 1)cout << endl;
        cout << "Game " << round << ": ";
        if(flag) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
        
    }
    return 0;
}
