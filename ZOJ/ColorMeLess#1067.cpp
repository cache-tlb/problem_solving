#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 16;
int main()
{
	int r[N] = {}, g[N] = {}, b[N] = {};
	for(int i = 0; i < N; i++){
		cin >> r[i] >> g[i] >> b[i];
	}
	int x, y, z;
	while(cin >> x >> y >> z){
		if(x==-1 && y== -1 && z== -1) break;
		int mini = 255*255*3, k = 0;
		for(int i = 0; i < N; i++){
			int dsq = (r[i]-x)*(r[i]-x)+(g[i]-y)*(g[i]-y)+(b[i]-z)*(b[i]-z);
			if(dsq<mini){
				mini = dsq;
				k = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", x, y, z, r[k], g[k], b[k]);
	}
	return 0;
}
