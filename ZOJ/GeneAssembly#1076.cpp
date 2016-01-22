#include<iostream>
//#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 50002;
struct exon{
	int start, end, num;
};
/*int cmp(exon a, exon b){
	if(a.end!=b.end)
		return a.end - b.end;
	else
		return a.start - b.start;
}*/
bool operator >= (exon a, exon b)
{
	if(a.end!=b.end)
		return a.end >= b.end;
	else
		return a.start >= b.start;
}
bool operator <= (exon a, exon b)
{
	if(a.end!=b.end)
		return a.end <= b.end;
	else
		return a.start <= b.start;
}
void sort1(exon array[], int zz,int yy)
{
     int z,y;
	 exon k;
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

int main()
{
	int n;
	while(cin >> n){
		if(!n) break;
		exon ex[MAXN] = {};
		for(int i = 0; i < n; i++){
			cin >> ex[i].start >> ex[i].end;
			ex[i].num = i + 1;
		}
		sort1(ex, 0, n-1);
		//for(int i = 0; i < n; i++)
		//	cout << ex[i].start << ' ' << ex[i].end << ' ' << ex[i].num << endl;
		int p = 1, curstart = ex[0].end+1;
		vector<int> ans;
		ans.push_back(ex[0].num);
		while(p<n){
			while(ex[p].start<curstart) p++;
			if(p>=n) break;
			ans.push_back(ex[p].num);
			curstart = ex[p].end+1;
			p++;
		}
		int nans = ans.size();
		for(int i = 0; i < nans; i++){
			cout << ans[i];
			if(i==nans-1) cout << endl;
			else cout << ' ';
		}
	}
	return 0;
}
