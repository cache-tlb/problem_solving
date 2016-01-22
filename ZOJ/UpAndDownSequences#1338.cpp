#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
const int MAX = 30 + 10;
int main()
{
	int temp;
	cout << setiosflags(ios::fixed) << setprecision(6);
	while(cin >> temp){
		if(temp==0) break;
		int a[MAX] = {};
		a[0] = temp;
		int n = 1;
		while(cin >> temp){
			if(temp==0) break;
			a[n] = temp;
			n++;
		}
		int nInc = 0, nDec = 0, totInc = 0, totDec = 0, state = 0;
		int p = 0, q = 0;
		while(p<n && q<n){
			while(a[p]==a[q]) q++;
			if(q<n){
				if(a[q] > a[p]){
					while(q<n && a[q]>=a[q-1]) q++;
					totInc += (q - p - 1);
					nInc++;
					//if(q==n) totInc--;
				}
				else{
					while(q<n && a[q]<=a[q-1]) q++;
					totDec += (q - p - 1);
					nDec++;
					//if(q==n) totDec--;
				}
				p = q - 1;
			}
		}
		//cout << nInc << ' ' << nDec << endl;
		double ans1 = 0.0, ans2 = 0.0;
		if(nInc){
			ans1 = (double)totInc/(double)nInc;
		}
		if(nDec){
			ans2 = (double)totDec/(double)nDec;
		}
		printf("Nr values = %d:  ",n);
		cout << ans1 << ' ' << ans2 << endl;
	}
	return 0;
}
