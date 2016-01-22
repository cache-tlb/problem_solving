#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n){
		int a = 0, b = 0, temp = 0;
		for(int i = 0; i < n; i++){
			cin >> temp;
			if(i%2){
				if(temp == 1) a++;
				else b++;
			}
			else{
				if(temp == 1) b++;
				else a++;
			}
		}
		if(a < b) cout << a << endl;
		else cout << b << endl;
	}
	return 0;
}
