#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 202;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int t;
	//freopen("in.txt","r",stdin);
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a, b;
		int times[MAXN] = {};
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			if(a > b) swap(a, b);
			int start = (a - 1)/2, end = (b - 1)/2;
			for(int i = start; i <= end; i++){
				times[i]++;
			}
		}
		int ans = 0;
		for(int i = 0; i < MAXN; i++){
			if(times[i] > ans) ans = times[i];
		}
		cout << ans*10 << endl;
	}
	return 0;
}
