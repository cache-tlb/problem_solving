#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double i = 0, n = 0;
    while(cin >> n){
        if(n == 0) break;
        for(i = 0; i < 32; i++){
            if(pow(2,i) >= n)break;
        }
        cout << i <<endl;    
    }    
    return 0;
}
