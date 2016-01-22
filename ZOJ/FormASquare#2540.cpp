#include<iostream>
using namespace std;
struct POINT{
	int x,y;
};
int dis2(POINT a, POINT b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool isSquare(POINT a, POINT b, POINT c,POINT d)
{
	if(dis2(a,b)==dis2(b,c) && dis2(a,b)==dis2(c,d) && dis2(a,b)==dis2(d,a) && dis2(a,c)==dis2(b,d))
		return true;
	else
		return false;
}
int main()
{
	int t;
	cin >> t;
	int round = 1;
	while(t--){
		POINT a,b,c,d;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		cout << "Case " << round << ':' << endl;
		bool ok = isSquare(a,b,c,d) || isSquare(a,b,d,c) || isSquare(a,c,b,d) || isSquare(a,c,d,b) || isSquare(a,d,b,c) || isSquare(a,d,c,b);
		if(ok)
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
		if(t)
			cout << endl;
		round++;
	}
	return 0;
}
