#include<iostream>
using namespace std;
const int MAX = 20 + 10;
int main()
{
    int r;
    int first = 1;
    while(cin >> r){
        if(r==0) break;
        if(first) first = 0;
        else cout <<endl;
        int pa = 0, pb = 0;
        int a[MAX], b[MAX];
        for(int i = 0; i < r; i++){
            cin >> a[i];
        }
        for(int i = 0; i < r; i++){
            cin >> b[i];
        }
        
        for(int i = 0; i < r; i++){
            if(a[i] == b[i]) continue;
            if(a[i] > b[i]){
                if(a[i] - b[i] >= 2) pa += a[i];
                else if((a[i]==2) && (b[i]==1)) pb += 6;
                else pb += a[i] + b[i];
            }
            else{
                if(b[i] - a[i] >= 2) pb += b[i];
                else if((a[i]==1) && (b[i]==2)) pa += 6;
                else pa += a[i] + b[i];
            }    
        }
        cout << "A has " << pa << " points. B has " << pb << " points." << endl;
    }        
    return 0;
}
