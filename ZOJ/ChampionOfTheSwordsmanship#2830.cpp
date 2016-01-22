#include<iostream>
using namespace std;
int matchs(int n)
{
	return n/2;
}
int main()
{
	int n;
	while(cin >> n){
		if(!n) break;
		cout << matchs(n) << endl;
	}
	return 0;
}
