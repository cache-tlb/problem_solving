#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
const int MAXN = 10000 + 10;
struct node{
	int a;
	string s;
};
/*
bool operator >=(node a,node b)
{
	return a.s>=b.s;
}
bool operator <=(node a,node b)
{
	return a.s<=b.s;
}
void operator = (node a, node b)
{
	a.a = b.a;
	a.s = b.s;
}*/
void sort1(node array[], int zz,int yy)
{
     int z,y;
	 node k;
     if(zz<yy)
     {
         z=zz;y=yy;k.a=array[z].a;k.s=array[z].s;
         do{
           while(z<y&&array[y].s>=k.s)y--;
             if(z<y)
             {
                 array[z].a=array[y].a;
				 array[z].s=array[y].s;
                 z++;   
             }       
           while(z<y&&array[z].s<=k.s)z++;
           if(z<y){
             array[y].a=array[z].a;
			 array[y].s=array[z].s;
		   }
         }while(z!=y);
         array[z].a=k.a;
		 array[z].s=k.s;
         sort1(array,zz,z-1);
         sort1(array,z+1,yy);    
     }
}
string convert(int x)
{
	string ans = "";
	int q = x/1000;
	if(q==1)
		ans += "M";
	else if(q==2)
		ans += "MM";
	else if(q==3)
		ans += "MMM";
	x %= 1000;
	//q = x/100;
	switch(x/100){
		case 1:
			ans += "C";
			break;
		case 2:
			ans += "CC";
			break;
		case 3:
			ans += "CCC";
			break;
		case 4:
			ans += "CD";
			break;
		case 5:
			ans += "D";
			break;
		case 6:
			ans += "DC";
			break;
		case 7:
			ans += "DCC";
			break;
		case 8:
			ans += "DCCC";
			break;
		case 9:
			ans += "CM";
			break;
		default:
			break;
	}
	x %= 100;
	//q = x/10;
	switch(x/10){
		case 1:
			ans += "X";
			break;
		case 2:
			ans += "XX";
			break;
		case 3:
			ans += "XXX";
			break;
		case 4:
			ans += "XL";
			break;
		case 5:
			ans += "L";
			break;
		case 6:
			ans += "LX";
			break;
		case 7:
			ans += "LXX";
			break;
		case 8:
			ans += "LXXX";
			break;
		case 9:
			ans += "XC";
			break;
		default:
			break;
	}
	x %= 10;
	switch(x){
		case 1:
			ans += "I";
			break;
		case 2:
			ans += "II";
			break;
		case 3:
			ans += "III";
			break;
		case 4:
			ans += "IV";
			break;
		case 5:
			ans += "V";
			break;
		case 6:
			ans += "VI";
			break;
		case 7:
			ans += "VII";
			break;
		case 8:
			ans += "VIII";
			break;
		case 9:
			ans += "IX";
			break;
		default:
			break;
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		node num[MAXN];
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			scanf("%d", &num[i].a);
			num[i].s = convert(num[i].a);
			//printf("%s ",num[i].s.c_str());
		}
		//cout << endl;
		sort1(num, 0, n - 1);
		for(int i = 0; i < n - 1; i++){
			printf("%d ",num[i].a);
		}
		printf("%d\n",num[n-1].a);
	}
	return 0;
}
