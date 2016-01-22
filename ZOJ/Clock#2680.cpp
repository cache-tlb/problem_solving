#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int NUM = 5;
const int dst = 2;
struct TIME{
	int h,m;
	double angle;
};
void dswp(double d1, double d2)
{
	double temp = d1;
	d1 = d2;
	d2 = temp;
}
bool operator >= (TIME t1, TIME t2){
	if(t1.angle != t2.angle)
		return t1.angle >= t2.angle;
	else if(t1.h != t2.h)
		return t1.h >= t2.h;
	else
		return t1.m >= t2.m;
}
void sort1(TIME array[], int zz,int yy)
{
	int z,y;
	TIME k;
	if(zz<yy){
		z=zz;y=yy;k=array[z];
		do{
			while(z<y && array[y]>=k)y--;
			if(z<y){
				array[z]=array[y];
				z++;
			}
			while(z<y && k>=array[z])z++;
			if(z<y){
				array[y]=array[z];
			}
		}while(z!=y);
		array[z]=k;
		sort1(array,zz,z-1);
		sort1(array,z+1,yy);
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		TIME t[NUM+1] = {};
		for(int i = 0; i < NUM; i++){
			int hh, mm;
			scanf("%d:%d", &hh, &mm);
			t[i].h = hh;
			t[i].m = mm;
			double ang1 = (double)(hh%12)*30.0 + (double)mm*0.5, ang2 = (double)mm*6.0;
			double ang = fabs(ang2 - ang1);
			if(ang > 180.0) ang = 360.0 - ang;
			t[i].angle = ang;
		}
		sort1(t, 0, NUM - 1);
		//for(int i = 0; i < NUM; i++)
		//	cout << t[i].h << ' ' << t[i].m << ' ' << t[i].angle << endl;
		int hh = t[dst].h, mm = t[dst].m;
		if(hh<10) cout << 0;
		cout << hh << ':';
		if(mm<10) cout << 0;
		cout << mm << endl;
	}
	return 0;
}
