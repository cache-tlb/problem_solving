//ciphercode[i] = (plaincode[k*i mod n] - i) mod 28.
//PlainCode = (CipherCode + i) % 28;
#include<iostream>
#include<string>
using namespace std;

const int MAX = 70 + 10;
int convert(char a)
{
    if(a == '_') return 0;
    else if(a == '.') return 27;
    else return (a - 'a' + 1);
}
int main()
{
    int k;
    while(cin >> k){
        if(!k) break;
        string ct;
        cin >> ct;
        char pt[MAX] = "";
        int len = ct.length();
        for(int i = 0; i < len; i++){
            int pc = (convert(ct[i])+i)%28;
            if(pc == 0) pt[(k*i)%len] = '_';
            else if(pc == 27) pt[(k*i)%len] = '.';
            else pt[(k*i)%len] = pc + 'a' - 1;
        }
        pt[len] = 0;
        cout << pt << endl;
    }    
    return 0;
}
