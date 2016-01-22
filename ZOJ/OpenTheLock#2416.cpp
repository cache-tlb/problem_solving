#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN = 10000;
struct node{
	int step;
	int num;
};
int visit[MAXN] = {};
void Ins(vector<node>& vn, int temp, int step){
	if(!visit[temp]){
		node n;
		n.num = temp;
		n.step = step;
		vn.push_back(n);
		visit[temp] = 1;
	}
}
void intswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int step(int src, int tar)
{
	vector<node> vn;
	node start;
	start.step = 0;
	start.num = src;
	visit[src] = 1;
	vn.push_back(start);
	int cur = 0;
	while(vn[cur].num != tar){
		int temp = 0, curnum = vn[cur].num, step = vn[cur].step + 1;
		int a[4];
		a[0] = curnum/1000;
		a[1] = (curnum%1000)/100;
		a[2] = (curnum%100)/10;
		a[3] = curnum%10;
		for(int i = 0; i < 4; i++){
			if(a[i]==1){
				a[i] = 9;
				temp = a[0]*1000+a[1]*100+a[2]*10+a[3];
				Ins(vn, temp, step);
				a[i] = 1;
			}
			else{
				a[i]--;
				temp = a[0]*1000+a[1]*100+a[2]*10+a[3];
				Ins(vn, temp, step);
				a[i]++;
			}
			if(a[i]==9){
				a[i] = 1;
				temp = a[0]*1000+a[1]*100+a[2]*10+a[3];
				Ins(vn, temp, step);
				a[i] = 9;
			}
			else{
				a[i]++;
				temp = a[0]*1000+a[1]*100+a[2]*10+a[3];
				Ins(vn, temp, step);
				a[i]--;
			}
		}
		for(int i = 0; i < 3; i++){
			intswap(a[i], a[i+1]);
			temp = a[0]*1000+a[1]*100+a[2]*10+a[3];
			Ins(vn, temp, step);
			intswap(a[i], a[i+1]);
		}
		cur++;
	}
	return vn[cur].step;
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		memset(visit,0,sizeof(visit));
		int src = 0, tar = 0;
		cin >> src >> tar;
		cout << step(src, tar) << endl;
	}
	return 0;
}
