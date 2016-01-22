#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

inline double sqr(double x){
	return x*x;
}
int main()
{
	double x1,x2,x3,y1,y2,y3,z1,z2,z3;
	while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3){
		double a = sqrt(sqr(x1-x2)+sqr(y1-y2)+sqr(z1-z2));
		double b = sqrt(sqr(x2-x3)+sqr(y2-y3)+sqr(z2-z3));
		double c = sqrt(sqr(x3-x1)+sqr(y3-y1)+sqr(z3-z1));
		double p = (a+b+c)/2.0;
		double ans = 4.0*(p-a)*(p-b)*(p-c)/(a*b*c);
		printf("%.3lf\n", ans*ans);
	}

	return 0;
}
