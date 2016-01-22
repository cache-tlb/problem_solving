#include<iostream>
//#include<map>
#include<string>
using namespace std;
const int MAXN = 102;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string front;
		cin >> front;
		string name[MAXN] = {};
		for(int i = 0; i < n; i++)
			cin >> name[i];
		int pos = 0;
		for(pos = 0; pos < n; pos++)
			if(name[pos]==front) break;
		pos = (pos + n/2)%n;
		cout << name[pos] << endl;
	}
	return 0;
}
