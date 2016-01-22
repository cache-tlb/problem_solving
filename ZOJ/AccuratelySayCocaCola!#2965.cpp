#include<iostream>
using namespace std;
const int MAXNUM = 802;
int table[MAXNUM] = {};
int a[MAXNUM] = {};
bool has7(int x)
{
	while(x){
		if(x%10==7) return true;
		x /= 10;
	}
	return false;
}
void Init()
{
	for(int i = 1; i < MAXNUM; i++){
		if(i%7==0 || has7(i))
			table[i] = 1;
	}
	int p = 1, q = 1;
	while(p<MAXNUM && q<MAXNUM){
		while(p<MAXNUM && !table[p]) p++;
		if(p==MAXNUM) break;
		q = p;
		while(q<MAXNUM && table[q]) q++;
		a[p] = q - p;
		p = q;
	}
}
int main()
{
	int t;
	cin >> t;
	Init();
	while(t--){
		int p;
		cin >> p;
		for(int i = 1; i < MAXNUM; i++){
			if(a[i] >= p){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
