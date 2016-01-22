#include<iostream>
using namespace std;
const int MAX = 100 + 10;
int main()
{
    int r[MAX][MAX]={ }, g[MAX][MAX] = { }, b[MAX][MAX] = { };
    int m, n;
    int k = 1;
    while(cin >> n >> m){
        if(!n && !m)
            break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> r[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> b[i][j];
            }
        }
        cout << "Case " << k << ":" <<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << (r[i][j] + g[i][j] + b[i][j])/3;
                if(j == m - 1)
                    cout << endl;
                else
                    cout << ',';
            }
        }
        k++;
    }
    
    return 0;
}
