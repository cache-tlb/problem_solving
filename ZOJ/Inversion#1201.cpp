#include<iostream>
#include<list>
using namespace std;
const int MAXN = 55;
void P(int n)
{
	int a[MAXN] = {};
	int m[MAXN] = {};
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		m[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= m[i]; j++){
			if(a[j] > i)
				cnt++;
		}
		cout << cnt;
		if(i==n) cout << endl;
		else cout << ' ';
	}
}
void I(int n)
{
	int a[MAXN] = {};
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	list<int> li;
	li.push_back(n);
	for(int i = n-1; i >=1; i--){
		int cnt = 0;
		list<int>::iterator it;
		for(it = li.begin(); it != li.end(); it++){
			if(*it > i){
				cnt++;
			}
			if(cnt>=a[i]) break;
		}
		if(cnt==a[i]) it++;
		li.insert(it, i);
	}
	int first = 1;
	for(list<int>::iterator it = li.begin(); it != li.end(); it++){
		if(first) first = 0;
		else cout << ' ';
		cout << *it;
	}
	cout << endl;
}
int main()
{
	int n;
	while(cin >> n){
		if(n==0) break;
		int a[MAXN] = {};
		char type;
		cin >> type;
		if(type=='P')
			P(n);
		else if(type=='I')
			I(n);
	}
	return 0;
}
