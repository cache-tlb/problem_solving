#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 10002;
struct NODE{
	int v[3];
	int parent;
	vector<int> child;
};
struct triple{
	int a[3];
};
NODE node[MAXN] = {};
triple work(int num)
{
	if(node[num].child.empty()){
		triple t;
		t.a[0] = node[num].v[0];
		t.a[1] = t.a[2] = -1;
		return t;
	}
	else{
		triple t;
		t.a[0] = node[num].v[0];
		t.a[1] = t.a[2] = -1;
		for(int i = 0; i < node[num].child.size(); i++){
			triple t1 = work(node[num].child[i]);
			for(int j = 0; j < 3; j++){
				if(t1.a[j]==-1) break;
				if(t1.a[j]>t.a[0]){
					t.a[2] = t.a[1];
					t.a[1] = t.a[0];
					t.a[0] = t1.a[j];
				}
				else if(t.a[1]<t1.a[j] && t1.a[j]<t.a[0]){
					t.a[2] = t.a[1];
					t.a[1] = t1.a[j];
				}
				else if(t.a[2]<t1.a[j] && t1.a[j]<t.a[1]){
					t.a[2] = t1.a[j];
				}
				else if(t1.a[j]==t.a[0]){
					t.a[2] = t.a[1];
					t.a[1] = t1.a[j];
				}
				else if(t1.a[j]==t.a[1]){
					t.a[2] = t1.a[j];
				}
			}
		}
		node[num].v[0] = t.a[0];
		node[num].v[1] = t.a[1];
		node[num].v[2] = t.a[2];
		return t;
	}
}
int main()
{
	int n;
	while(cin >> n){
		memset(node,0,sizeof(node));
		for(int i = 0; i < n; i++){
			node[i].v[0] = node[i].v[1] = node[i].v[2] = -1;
		}
		scanf("%d", &node[0].v[0]);
		for(int i = 1; i < n; i++){
			int pa;
			scanf("%d %d", &pa, &node[i].v[0]);
			node[pa].child.push_back(i);
			node[i].parent = pa;
		}
		work(0);
		int q;
		scanf("%d", &q);
		int num;
		while(q--){
			scanf("%d", &num);
			if(node[num].v[2]==-1)
				printf("%d\n", -1);
			else
				printf("%d %d %d\n", node[num].v[0], node[num].v[1], node[num].v[2]);
		}
	}
	return 0;
}
