#include<iostream>
#include<cmath>
using namespace std;
/*int round(double x)
{
	return (int)(x + 0.5);
}*/
int main()
{
	int test = 0;
	int w,d;
	while(cin >> w >> d){
		if(w==0 && d==0) break;
		test++;
		double t = log10(d/(w*810.0))/log10(0.5)*5730;
		cout << "Sample #" << test << endl;
		int ans = 0;
		if(t < 10000.0){
			ans = round(t/100);
			ans *= 100;
		}
		else{
			ans = round(t/1000);
			ans *= 1000;
		}
		cout << "The approximate age is " << ans << " years." << endl << endl;
	}
	return 0;
}
