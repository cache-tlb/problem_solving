#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 100005;
double table[MAXN] = {};
void Init()
{
	double cur = 0.5;
	table[1] = 0.5;
	for(int i = 2; i < MAXN; i++){
		table[i] = table[i-1] + 0.5/(double)i;
	}
}
int getdigit(int x)
{
	if(0<=x && x<=9) return 1;
	else if(10<=x && x<=99) return 2;
	else if(100<=x && x<=999) return 3;
	else if(1000<=x && x<=9999) return 4;
	else if(10000<=x && x<=99999) return 5;
}
int main()
{
	Init();
	cout << "# Cards  Overhang" << endl;
	int n;
	while(cin >> n){
		int times = 5 - getdigit(n);
		for(int i = 0; i < times; i++) cout << ' ';
		printf("%d     ", n);
		printf("%.3f\n", table[n]);
	}
	return 0;
}
