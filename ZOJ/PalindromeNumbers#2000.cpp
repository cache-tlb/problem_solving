#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int MAXDIG = 20;
long long table[MAXDIG];

string num2str(int num, int ndigit) {
    string s = string(ndigit, '0');
    int index = ndigit - 1;
    while(num) {
        int x = num % 10;
        s[index--] = x + '0';
        num /= 10;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    long long n;
    for(int i = 1; i < MAXDIG; i++){
        long long prod = 9;
        for(int j = 1; j + j - 1 <= i - 2; j++){
            prod *= 10;
        }
        table[i] = prod;
    }
    /*for(int i = 0; i < MAXDIG; i++){
        cout << table[i] << endl;
    }*/
    while(cin >> n) {
        if(n == 0) break;
        long long sum = 0;
        int ndigit = 0;
        for(int i = 1; i < MAXDIG; i++) {
            if(sum + table[i] >= n){
                ndigit = i;
                break;
            }
            sum += table[i];
        }
        if(ndigit==1){
            cout << n << endl;
        }
        else if(ndigit==2){
            cout << n - 9 << n - 9 << endl;
        }
        else if(ndigit % 2 == 0){
            int index = n - sum - 1;
            string str = num2str(index, (ndigit+1)/2);
            str[0]++;
            for(int i = 0; i < str.length(); i++){
                cout << str[i];
            }
            for(int i = str.length() - 1; i >= 0; i--){
                cout << str[i];
            }
            cout << endl;
        }
        else {
            int index = n - sum - 1;
            string str = num2str(index, (ndigit+1)/2);
            str[0]++;
            for(int i = 0; i < str.length(); i++){
                cout << str[i];
            }
            for(int i = str.length() - 2; i >= 0; i--){
                cout << str[i];
            }
            cout << endl;
        }
    }
    return 0;
}
