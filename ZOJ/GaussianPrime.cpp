#include<iostream>
//#include<cmath>
using namespace std;
const int MAX = 2*10000 + 10;
int prime[MAX]={};	//0 for prime
void ini()
{
    int d = 2;
    do{
        int k = d;
        if(prime[k]==0){
            k += d;
            while(k <= MAX){
                prime[k] = 1;
                k += d;
            }
        }
        d++;
    }while(d*d<=MAX);
    //for(int i = 2; i <= MAX; i++){
    //    if(!prime[i]) cout << i << ' ';
    //}        
}
int gcd(int x,int y){
	int ans = 1;
	if(x%y==0)
		ans = y;
	else
		ans = gcd(y,x%y);
	return ans;
}
int ABS(int x)
{
	if(x>=0) return x;
	else return -x;
}
int main()
{
	int x1,y1,x2,y2;
	int t;
	cin >> t;
	ini();
	while(t--){
		cin >> x1 >> x2 >> y1 >> y2;
		int temp;
		if(x1>x2){
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if(y1>y2){
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		int a,b;
		int cnt = 0;
		for(a = x1; a <= x2; a++){
			for(b = y1; b <= y2; b++){
				if(a==0 && (ABS(b)%4)==3 && !prime[ABS(b)]) cnt++;
				else if(b==0 && (ABS(a)%4)==3 && !prime[ABS(a)]) cnt++;
				else if(a!=0 && b!=0 && !prime[a*a+b*b]) cnt ++;
			}
		}
		int tot = (x2-x1+1)*(y2-y1+1);
		int d = gcd(cnt,tot);
		cout << cnt/d << '/' << tot/d << endl;
		//if(cnt!=0) cout << cnt/d << '/' << tot/d << endl;
		//else cout << 0 << '/' << tot << endl;
	}
	return 0;
}
