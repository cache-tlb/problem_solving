#include<iostream>
using namespace std;
const int MAXN = 155;
int main()
{
	int n;
	while(cin >> n){
		if(n==0) break;
		n--;
		int m = 2;
		int temp = 0;
		while(1){
			temp = 0;
			for(int i = 2; i <= n; i++){
				temp = (temp+m)%i;
			}
			if(temp==0) break;
			else m++;
		}
		cout << m << endl;
	}
	return 0;
}
