#include <cstdio>
#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 200;
int n;
struct point{
	int x,y;
	point(){}
	point(int a, int b){x=a;y=b;}
};

bool operator < (const point& p1, const point &p2){
	return p1.x < p2.x || (p1.x==p2.x && p1.y < p2.y);
}

bool turn_right(point &p1, point &p2, point &p3){
	point v1(p2.x-p1.x,p2.y-p1.y);
	point v2(p3.x-p2.x,p3.y-p2.y);
	return v1.x*v2.y-v1.y*v2.x < 0;
}

list<point> convex_u;
list<point> convex_l;

point p[MAXN];

int main(int argc, char const *argv[])
{
	
	while(cin >> n){
		if(!n) break;
		for(int i = 0; i < n; i++){
			cin >> p[i].x >> p[i].y;
		}
		sort(p,p+n);
		if(n==1){
			printf("%.2lf\n", 0.00);
			continue;
		}
		else if(n==2){
			double len = hypot(p[0].x-p[1].x,p[0].y-p[1].y);
			printf("%.2lf\n", len*2.0);
			continue;
		}
		convex_u.clear();
		convex_l.clear();
		convex_u.push_back(p[0]);
		convex_u.push_back(p[1]);

		for(int i = 2; i < n; i++){
			convex_u.push_back(p[i]);
			while(convex_u.size() >= 3){
				point p3 = convex_u.back(); convex_u.pop_back();
				point p2 = convex_u.back(); convex_u.pop_back();
				point p1 = convex_u.back(); convex_u.pop_back();
				if(!turn_right(p1,p2,p3)){
					convex_u.push_back(p1);
					convex_u.push_back(p3);
				}
				else{
					convex_u.push_back(p1);
					convex_u.push_back(p2);
					convex_u.push_back(p3);
					break;
				}
			}
		}
		convex_l.push_back(p[n-1]);
		convex_l.push_back(p[n-2]);
		for(int j = n - 3; j >= 0; j--){
			convex_l.push_back(p[j]);
			while(convex_l.size() >= 3){
				point p3 = convex_l.back(); convex_l.pop_back();
				point p2 = convex_l.back(); convex_l.pop_back();
				point p1 = convex_l.back(); convex_l.pop_back();
				if(!turn_right(p1,p2,p3)){
					convex_l.push_back(p1);
					convex_l.push_back(p3);
				}
				else{
					convex_l.push_back(p1);
					convex_l.push_back(p2);
					convex_l.push_back(p3);
					break;
				}
			}
		}

		convex_l.pop_front();
		vector<point> v;
		for(list<point>::iterator it = convex_u.begin(); it != convex_u.end(); it++){
			v.push_back(point(it->x, it->y));
		}
		for(list<point>::iterator it = convex_l.begin(); it != convex_l.end(); it++){
			v.push_back(point(it->x,it->y));
		}

		double sum = 0.0;
		for(int i = 1; i < v.size(); i++){
			sum += hypot((double)(v[i].x-v[i-1].x), (double)(v[i].y-v[i-1].y));
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}
