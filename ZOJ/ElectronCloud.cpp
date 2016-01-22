#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define PI 3.1415926535898
int main()
{
	int t;
	cin >> t;
	cout << setiosflags(ios::fixed) << setprecision(2);
	while(t--){
		double x1,x2,y1,y2,z1,z2,r1,r2;
		double ans = 0.0;
		cin >> x1 >> y1 >> z1 >> r1 >> x2 >> y2 >> z2 >> r2;
		if(r1<r2){
			double tmp = x1;
			x1 = x2; x2 = tmp;
			tmp = y1; y1 = y2; y2 = tmp;
			tmp = z1; z1 = z2; z2 = tmp;
			tmp = r1; r1 = r2; r2 = tmp;
		}
		double d_sqr = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
		double d = sqrt(d_sqr);
		if(r1+r2 <= d){
			ans = 4.0*PI/3.0*(r1*r1*r1 + r2*r2*r2);
		}
		else if(r1 >= r2+d){
			ans = 4.0*PI/3.0*r1*r1*r1;
		}
		else {	//assert d>0
			double r = sqrt((r1+r2+d)*(r1+r2-d)*(r1+d-r2)*(r2+d-r1))/2.0/d;
			//cout << "r = " << r << endl;
			double d1 = sqrt(r1*r1-r*r), d2 = sqrt(r2*r2-r*r);
			double h1 = r1 - d1;
			double h2;
			/*if(d<r1){
				h2 = r2 + d2;
			}
			else*/ h2 = r2 - d2;
			ans = 4.0*PI/3.0*(r1*r1*r1+r2*r2*r2) 
				- PI/3.0*((3.0*r1-h1)*h1*h1+(3.0*r2-h2)*h2*h2);
		}
		cout << ans << endl;
	}
	return 0;
}
