#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int x, y;
	while(cin >> x >> y){
		if(x==0 && y==0) break;
		int maxx = -INT_MAX;
		int minx = INT_MAX;
		int maxy = maxx;
		int miny = minx;
		if(maxx < x) maxx = x;
		if(minx > x) minx = x;
		if(maxy < y) maxy = y;
		if(miny > y) miny = y;
		//cout << x << y << endl;
		while(cin >> x >> y){
			//cout << x << y <<endl;
			if(x==0 && y==0) break;
			if(maxx < x) maxx = x;
			if(minx > x) minx = x;
			if(maxy < y) maxy = y;
			if(miny > y) miny = y;
		}
		cout << minx << ' ' << miny << ' ' << maxx << ' ' << maxy << endl;
	}
	return 0;
}
