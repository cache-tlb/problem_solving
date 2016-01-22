#include<iostream>
using namespace std;
const int MAXN = 12;
struct window{
	int x1,y1,x2,y2;
};
int main()
{
	int n;
	window w[MAXN] = {};
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> w[i].x1 >> w[i].y1 >> w[i].x2 >> w[i].y2;
	}
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		int ans = -1;
		for(int i = n - 1; i >= 0; i--){
			if(w[i].x1<=x && x<=w[i].x2 && w[i].y1<=y && y<=w[i].y2){
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
