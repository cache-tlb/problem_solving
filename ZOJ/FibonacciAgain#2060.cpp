//list several number and find the regular
#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >> n){
        if(n%4 == 2) cout << "yes" <<endl;
        else cout << "no" << endl;
    }    
    return 0;
}
