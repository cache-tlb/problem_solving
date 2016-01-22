#include<iostream>
#include<vector>
using namespace std;
const int MAX = 100000 + 10;

//int judge[MAX*3] = {};
int main()
{
    vector<int> f;
    for(int i = 1; i <= MAX*3; i++){
        if(i%3==0 || i%5==0){
            f.push_back(i);
        }
    }
    int k;
    while(cin >> k){
        cout << f[k - 1] << endl;
    }            
    return 0;
}
