#include<iostream>
#include<map>
using namespace std;
const int MAXN = 103;
int main()
{
	int n;
	while(cin >> n){
		if(!n) break;
		map<int,int> mi;
		int temp;
		for(int i = 0; i < n; i++){
			cin >> temp;
			mi[temp] = 1;
		}
		int first = 1;
		for(map<int,int>::iterator it = mi.begin(); it != mi.end(); it++){
			if(first) first = 0;
			else cout << ' ';
			cout << it->first;
		}
		cout << endl;
	}
	return 0;
}
