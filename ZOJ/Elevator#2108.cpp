#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    while(cin >> n){
        if(n == 0) break;
        int pre = 0, cur = 0, time = 0;
        for(int i = 0; i < n; i++){
            cin >> cur;
            //cout << "--------"<< endl;
            //cout << "cur = " << cur <<endl;
            if(pre < cur) time += 6*(cur - pre);
            if(pre > cur) time += 4*(pre - cur);
            time += 5;
            pre = cur;
        }
        cout << time <<endl;
    }    
    return 0;
}
