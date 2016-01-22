#include <iostream>
using namespace std;

const int MAX = 100;
int vis[MAX+1] = {};
int flag = 0;//wether it's sure that challenger succeed 
int success = 0;
void work(int big, int small, int pb, int ps){
    if(flag){
        return;
    }
    if((small == 1)){// possiblely find a correct way to factorize the challenger's number.
        success = 1;
        if(big != 1){
            for(int i = pb + 1; i <= MAX; i++){ // try to factorize the defencer's number
                                                // if failed, keep success = 1
                if(flag) break;
                if((big%i == 0) && (!vis[i])){
                    vis[i] = 1;
                    work(big/i, 1, i, ps);
                    vis[i] = 0;
                }
            }    
        }
        else {
            success = 0; // if correctly factorize both number, defencer win.
            flag = 1;
        }
    }
    else for(int i = ps + 1; i <= MAX; i++){// try to factorize the challenger's number
                                            // if failed ,nothing to do (keep success = 0)
        if(flag) break;
        if((small%i == 0) && (!vis[i])){
            vis[i] = 1;
            work(big, small/i, pb, i);
            vis[i] = 0;
        }
    }  
}

int main()
{
    int a, b;
    while(cin >> a >> b){
        if(a < b){
            int temp = a;
            a = b;
            b = temp;
        }
        flag = 0;
        success = 0;
        work(a, b, 1, 1);
        if(success == 1) cout << b << endl;
        else cout << a << endl;    
    }
    return 0;
}
