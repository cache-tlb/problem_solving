#include<iostream>
using namespace std;
const int MAX = 100 + 10;

int sr[MAX] = {};
int sc[MAX] = {};
int a[MAX][MAX] = {};
int main()
{
    int n;
    while(cin >> n){
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        //calculate sum of row and col
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += a[i][j];
            }
            sr[i] = sum;
        }
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += a[i][j];
            }
            sc[j] = sum;
        }
        //judge
        int ii = -1, jj = -1, cnt_i = 0, cnt_j = 0;
        for(int i = 0; i < n; i++){
            if(sr[i]%2){
                ii = i + 1;
                cnt_i++;
            }
            if(sc[i]%2){
                jj = i + 1;
                cnt_j++;
            }
        }
        if((cnt_i == 0) && (cnt_j == 0)) cout << "OK" << endl;
        else if((cnt_i == 1) && (cnt_j == 1)) cout << "Change bit (" << ii << ',' << jj << ")" <<endl;
        else cout << "Corrupt" <<endl;
    }
    return 0;
}
