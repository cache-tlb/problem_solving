#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	double a, b, c, d, e, f;
	scanf("%d", &t);
	while(t--){
		scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
		double temp = a*c;
		if(a==c && a!=0.0) printf("circle\n");
		else if(temp<0.0) printf("hyperbola\n");
		else if((a!=0.0&&c==0.0&&e!=0.0) || (a==0.0&&c!=0.0&&d!=0.0)) printf("parabola\n");
		else if(temp>0.0 && a!=c)printf("ellipse\n");
	}
	return 0;
}
