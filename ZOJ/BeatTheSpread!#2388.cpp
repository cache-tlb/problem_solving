#include <iostream>
using namespace std;

int ABS(int x){
    return (x>=0) ? x : -x;
}    
int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int x = ABS((a + b)/2), y = ABS((a - b)/2);
        if( (a < b) || (a+b)%2 ) cout << "impossible" << endl;
        else cout << x << ' ' << y << endl;
    }    
    return 0;
}
