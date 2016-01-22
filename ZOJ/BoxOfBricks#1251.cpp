#include<iostream>
using namespace std;
const int MAX = 50+10;
int main()
{
    int n;
    cin>>n;
    int round = 1;
    while(n){
        int ans = 0,sum = 0;
        int b[MAX];
        for(int i=0;i<n;i++){
            cin>>b[i];
            sum += b[i];
        }
        int ave = sum/n;
        for(int i=0;i<n;i++){
            if(b[i]>ave){
                ans += b[i]-ave;
            }
        }
        cout<<"Set #"<<round<<endl<<"The minimum number of moves is "<<ans<<'.'<<endl<<endl;            
        cin>>n;
        round++;
    }    
    return 0;
}

