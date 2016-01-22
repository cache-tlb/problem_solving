#include <iostream>
using namespace std;
int ludi(float x, float y)
{
    return 3.1416 * (x * x + y * y) / 100 + 1;
}

int main()
{
    int     n;
    float   a, b;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >>b;
        cout << "Property " << i << ": This property will begin eroding in year "
             << ludi(a, b) << '.' << endl;
    }
    cout << "END OF OUTPUT." <<endl;
    return 0;
}

