#include<iostream>
#include<cstdio>
//#include<algorithm>
using namespace std;
const int MAXN = 50002;
struct stick{
	int len, weight;
};
/*int cmp(stick& s1, stick& s2)
{
	if(s1.len == s2.len)
		return s2.weight - s1.weight;
	else return s1.len - s2.len;
}*/
bool operator >= (stick s1, stick s2)
{
	if(s1.len == s2.len)
		return s1.weight >= s2.weight;
	else return s1.len >= s2.len;
}
bool operator <= (stick s1, stick s2)
{
	if(s1.len == s2.len)
		return s1.weight <= s2.weight;
	else return s1.len <= s2.len;
}
void sort1(stick array[], int zz,int yy)
{
	int z,y;
	stick k;
	if(zz<yy){
		z=zz;y=yy;k=array[z];
		do{
			while(z<y&&array[y]>=k)y--;
			if(z<y){
				array[z]=array[y];
				z++;
			}
			while(z<y&&array[z]<=k)z++;
			if(z<y){
				array[y]=array[z];
			}
		}while(z!=y);
		array[z]=k;
		sort1(array,zz,z-1);
		sort1(array,z+1,yy);
	}
}
int LIS(int a[], int n)
{
	int b[MAXN] = {};
	int ans = 1;
	b[0] = 1;
	for(int i = 0; i < n; i++){
		int temp = 0;
		for(int j = 0; j < i; j++){
			if(a[i]>a[j] && b[j]>temp) temp = b[j];
		}
		b[i] = temp + 1;
	}
	for(int i = 0; i < n; i++)
		if(ans < b[i]) ans = b[i];
	return ans;
}
int main()
{
	int t;
	//freopen("in.txt","r",stdin);
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		stick s[MAXN] = {};
		for(int i = 0; i < n; i++){
			cin >> s[i].len >> s[i].weight;
		}
		sort1(s, 0, n - 1);
		//for(int i = 0; i < n; i++)
		int a[MAXN] = {};
		for(int i = 0; i < n; i++){
			a[i] = s[n - i - 1].weight;
		}
		cout << LIS(a, n) << endl;
	}
	return 0;
}
