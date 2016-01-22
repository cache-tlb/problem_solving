#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 5842;
const double MAXNUM = 2000000000;
vector<double> ans;
void sort1(vector<double> array, int zz,int yy)
{
     int z,y;
	 double k;
     if(zz<yy)
     {
         z=zz;y=yy;k=array[z];
         do{
             while(z<y&&array[y]>=k)y--;
             if(z<y)
             {
                 array[z]=array[y];
                 z++;   
             }       
             while(z<y&&array[z]<=k)z++;
             if(z<y){
                 array[y]=array[z];
         }
         }while(z!=y);
         array[z]=k;
         sort1(array,zz,z-1);
         sort1(array,z+1,yy);
     }
}
void Init()
{
	for(double s7 = 1; s7 <= MAXNUM; s7 *= 7){
		for(double f5 = 1; f5 <= MAXNUM; f5 *= 5){
			for(double t3 = 1; t3 <= MAXNUM; t3 *= 3){
				for(double t2 = 1; t2 <= MAXNUM; t2*= 2){
					ans.push_back(t2*t3*f5*s7);
				}
			}
		}
	}
	int n = ans.size();
	sort(ans.begin(),ans.end());
}
int main()
{
	Init();
	int i;
	while(cin >> i){
		if(i==0) break;
		cout << "The " << i;
		int ii = i%10;
		if(ii==1 && i%100!=11)cout << "st";
		else if(ii==2 && i%100!=12) cout << "nd";
		else if(ii==3 && i%100!=13) cout << "rd";
		else cout << "th";
		cout << " humble number is " << (int)ans[i-1] << '.' << endl;
	}
	return 0;
}
