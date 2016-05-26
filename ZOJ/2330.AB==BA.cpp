#include<iostream>
#include<iomanip>
#include<cmath>
#define ex 2.718281828459
#define EPSILON 1e-11
using namespace std;
double solve(double dst, double lo, double hi)
{
	if(hi - lo < EPSILON)
		return lo;
	double mid = (lo+hi)/2.0;
	if((log(lo)/lo-dst)*(log(mid)/mid-dst)<0)
		return solve(dst, lo, mid);
	else
		return solve(dst, mid, hi);
}
int main()
{
	cout << setiosflags(ios::fixed) << setprecision(5);
	double a;
	//cout << log(ex) << endl;
	const double up = log(ex)/ex;
	while(cin >> a){
		double m = log(a)/a;
		if(a - ex > 0){
			cout << "-1" << endl;
			continue;
		}
		double ans = 0.0;
		if(a - ex > 0){
			ans = solve(m, 1.1, ex);
		}
		else{
			double ub = ex;
			while(log(ub)/ub >= m)
				ub *= 2;
			ans = solve(m, ex, ub);
		}
		cout << ans << endl;
	}
	return 0;
}
