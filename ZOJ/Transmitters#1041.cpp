#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 155;
const double pi = 3.141592658979323;
struct point{
	double x,y;
	bool in;
};
double tx,ty,r;
bool incircle(double x,double y,double cx,double cy,double r)
{
	double d2 = (x-cx)*(x-cx) + (y-cy)*(y-cy);
	if(d2<=r*r) return true;
	else return false;
}
bool ccw(point p1, point p2){
	double dx1 = p1.x - tx, dx2 = p2.x - tx;
	double dy1 = p1.y - ty, dy2 = p2.y - ty;
	double c = dx1*dy2 - dx2*dy1;
	if(c>=0.0) return true;
	else return false;
}
int main()
{
	while(cin >> tx >> ty >> r){
		if(r < 0.0) break;
		int n;
		cin >> n;
		point p[maxn] = {};
		for(int i = 0; i < n; i++){
			cin >> p[i].x >> p[i].y;
			if(incircle(p[i].x,p[i].y,tx,ty,r)) p[i].in = true;
			else p[i].in = false;
		}
		int ans = 0;//!!!!!!!!notice here!!!!!!!!!
		for(int i = 0; i < n; i++){
			if(!p[i].in) continue;
			double a,b;
			int cnt = 0;
			for(int j = 0; j < n; j++){
				if(!p[j].in) continue;
				if(ccw(p[i],p[j])) cnt++;
			}
			if(ans<cnt) ans = cnt;
		}
		cout << ans << endl;
	}
	return 0;
}
