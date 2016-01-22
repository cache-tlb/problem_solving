#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    double a=0.0,b=0.0,c=0.0;
    cin>>a>>b>>c;
    int round = 0;
    cout<<setiosflags(ios::fixed)<<setprecision(3);
    while(a||b||c){
        round++;
        cout<<"Triangle #"<<round<<endl;
        double ans = -1.0;
        if(a==-1){
            if(b<c){
                ans = sqrt(c*c-b*b);
                cout<<"a = ";
            }    
        }
        else if(b==-1){
            if(a<c){
                ans = sqrt(c*c-a*a);
                cout<<"b = ";
            }    
        }
        else if(c==-1){
            ans = sqrt(a*a+b*b);
            cout<<"c = ";
        }
        if(ans == -1.0)cout<<"Impossible."<<endl;
        else cout<<ans<<endl;
        cout<<endl;
        cin>>a>>b>>c;
    }    
    return 0;
}
