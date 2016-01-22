#include<iostream>
#include<cstring>
using namespace std;
const int SIZE = 20;
const int NSTATE = 16;
const int MAXDEN = 3;
int den(int a[SIZE][SIZE], int i, int j)
{
	int ans = a[i][j];
	if(i>0)
		ans += a[i-1][j];
	if(i+1<SIZE)
		ans += a[i+1][j];
	if(j>0)
		ans += a[i][j-1];
	if(j+1<SIZE)
		ans += a[i][j+1];
	return ans;
}
void update(int a[SIZE][SIZE], int D[NSTATE])
{
	int b[SIZE][SIZE] = {};
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j <SIZE; j++){
			b[i][j] = a[i][j] + D[den(a,i,j)];
			if(b[i][j]>MAXDEN) b[i][j] = MAXDEN;
			else if(b[i][j]<0) b[i][j] = 0;
		}
	}
	//memcpy(a,b,sizeof(a));
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			a[i][j] = b[i][j];
}
int main()
{
	int t;
	cin >> t;
	const char* trans = ".!X#";
	while(t--){
		int k;
		cin >> k;
		int a[SIZE][SIZE] = {};
		int D[NSTATE] = {};
		for(int i = 0; i < NSTATE; i++)
			cin >> D[i];
		for(int i = 0; i < SIZE; i++)
			for(int j = 0; j < SIZE; j++)
				cin >> a[i][j];
		while(k--)
			update(a,D);
		for(int i = 0; i < SIZE; i++){
			for(int j = 0; j < SIZE; j++){
				cout << trans[a[i][j]];
			}
			cout << endl;
		}
		if(t) cout << endl;
	}
	return 0;
}
