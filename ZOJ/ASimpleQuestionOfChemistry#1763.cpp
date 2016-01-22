#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double a=0.0,b=0.0;
    cin>>a;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    while(cin>>b){
        if(b==999){
            cout<<"End of Output"<<endl;
            break;
        }
        cout<<b-a<<endl;
        a=b;
    }    
    return 0;
}    
