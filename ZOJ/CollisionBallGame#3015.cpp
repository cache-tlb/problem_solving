#include<iostream>
#include<cstdio>
#include<cmath>
#define pi 3.14159265358979323
using namespace std;
int main()
{
	double k, h, a, b;
	while(cin >> k >> h >> a >> b){
		double sink = sin(k/180.0*pi), cosk = cos(k/180.0*pi),
			   tank = tan(k/180.0*pi);
		double c = h/tank;
		double em = (h*(c-b)-(h-a)*(c-b)*sink*sink-(c-b)*(c-b)*sink*cosk)/((h-a)*cosk+(c-b)*sink),
			   eb = (c-b)*sink;
		double bm = sqrt((em)*(em)+(eb)*(eb)),
			   lamda = (h-a)*cosk/(c-b)/sink;
		printf("%.2f\n", (1.0+lamda)*bm);
	}
	return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double k,h,a,b,t1,t2,d,pi,f;
	pi=acos((double)-1);
	while(cin>>k>>h>>a>>b){
		t1=2*(h*sin(k*pi/180)*cos(k*pi/180)-b*sin(k*pi/180)*sin(k*pi/180))+b;
		t2=(t1-b)*cos(k*pi/180)/sin(k*pi/180);
		d=sqrt(t1*t1+(t2-a)*(t2-a));
		printf("%0.2lf\n",d);
	}
	return 0;
}
*/
