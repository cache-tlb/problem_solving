#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAX = 50 + 10;
int gcd(int a,int b)
{
    if(a%b==0)
	return b;
    else
	return gcd(b,a%b);
}
int main()
{
    int n;
    cout << setiosflags(ios::fixed) << setprecision(6);
    while(cin >> n){
	if(n==0)
	    break;
	int a[MAX] = { };
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	}
	int tot = 0, pri = 0;
	for(int i = 0; i < n - 1; i++){
	    for(int j = i + 1; j < n; j++){
		tot++;
		if(gcd(a[i],a[j])==1)
		    pri++;
	    }
	}
	if(pri==0)
	    cout << "No estimate for this data set." << endl;
	else
	    cout << sqrt(double(tot)*6.0/(double)pri) << endl;
    }
    return 0;
}
