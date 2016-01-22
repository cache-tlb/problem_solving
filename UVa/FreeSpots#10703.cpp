#include<iostream>
using namespace std;
const int MAXN = 100;
struct board{
	int x1,x2,y1,y2;
};
int swapint(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int w,h,n;
	while(cin >> w >> h >> n){
		if(w==0 && h==0 && n==0) break;
		board b[MAXN] = {};
		for(int i = 0; i < n; i++){
			cin >> b[i].x1 >> b[i].y1 >> b[i].x2 >> b[i].y2;
			if(b[i].x1 > b[i].x2) swapint(b[i].x1,b[i].x2);
			if(b[i].y1 > b[i].y2) swapint(b[i].y1,b[i].y2);
		}
		int cnt = 0;
		for(int x = 1; x <= w; x++){
			for(int y = 1; y <= h; y++){
				int ok = 0;
				for(int i = 0; i < n; i++){
					if(b[i].x1<=x && x<=b[i].x2 && b[i].y1<=y && y<=b[i].y2){
						ok = 1;
						break;
					}
				}
				if(!ok) cnt++;
			}
		}
		if(cnt==0) cout << "There is no empty spots." << endl;
		else if(cnt==1) cout << "There is one empty spot." << endl;
		else cout << "There are " << cnt << " empty spots." << endl;
	} 
	return 0;
}
