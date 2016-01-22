#include<iostream>
using namespace std;
const int MAX = 65535;
int bound[MAX+10] = {};
void ini()
{
    bound[0] = 0;
    for(int i = 0; i < MAX; i++){
        if((i+1)%2){
            bound[i+1] = (i+2)*(i+2)/4;
        }
        else{
            bound[i+1] = (i+1)*(i+3)/4;
        }
    }            
}
void work(int x)
{
    if(x==0){
        cout << 0 <<endl;
        return ;
    }    
    for(int i = 0; i < MAX; i++){
        if( (bound[i] < x) && (bound[i+1] >= x) )
            cout<<i+1<<endl;
    }    
}
int main()
{
    int a,b;
    ini();
    //for(int i = 1; i < 100; i++){
    //    work(i);
    //}    
    while(cin >> a >> b){
        work(b-a);
    }    
    return 0;
}
