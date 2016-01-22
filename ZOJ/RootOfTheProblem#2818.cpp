#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int b,n;
	while(cin >> b >> n){
		if(!b && !n) break;
		int i = 1;
		while(pow((double)i,(double)n)<=b) i++;
		if(i > 1){
			double d1 = pow((double)(i-1),(double)n) - (double)b;
			double d2 = pow((double)i, (double)n) - (double)b;
			if(abs(d1) <= abs(d2)) cout << i - 1 << endl;
			else cout << i << endl;
		}
		else cout << 1 << endl;
	}
	return 0;
}
