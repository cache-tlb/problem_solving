#include<iostream>
using namespace std;
const int MAXN = 100005;
double table[MAXN] = {};
void Init()
{
	table[1] = 0.5;
	for(int i = 2; i < MAXN; i++){
		table[i] = table[i-1] + 1.0/(double)(i+1);
	}
}
int main()
{
	double len = 0.0;
	Init();
	while(cin >> len){
		if(len==0.0) break;
		int i = 1;
		for(i = 1; i < MAXN; i++){
			if(table[i]>=len) break;
		}
		cout << i << " card(s)" << endl;
	}
	return 0;
}
