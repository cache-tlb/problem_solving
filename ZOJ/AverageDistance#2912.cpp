#include <iostream>
#include <list>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <cstdio>

using namespace std;

const int MAXN = 10002;

struct node{
	int id;
	int nPoints;
	int parent_pos;
	int len;
	node(int _id, int _np, int _parent_pos, int _len){
		id = _id;
		nPoints = _np;
		parent_pos = _parent_pos;
		len = _len;
	}
	node(){}
};

/////////////////////////////////////////////////////////////////////////////////

int main()
{
	//2 <= n <= 10 000
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		list<pair<int,int> > neighbors[MAXN];
		int u, v, val;
		for (int i = 0; i < n - 1; i++) {
			scanf("%d%d%d", &u, &v, &val);
			neighbors[u].push_back(pair<int,int>(v,val));
			neighbors[v].push_back(pair<int,int>(u,val));
		}
		node tree[MAXN] = {};
		int curpos = 0;
		int tail = 0;
		int id2pos[MAXN] = {};
		memset(id2pos, -1, sizeof(id2pos));
		node head(0,1,-1,0);
		tree[tail++] = head;
		id2pos[0] = 0;

		while(tail < n){
			node &item = tree[curpos];
			int id = item.id;
			for(list<pair<int,int> >::iterator it = neighbors[id].begin(); it != neighbors[id].end(); it++) {
				int nid = it->first;
				if(id2pos[nid] < 0){
					node newnode(nid, 1, curpos, it->second);
					tree[tail] = newnode;
					id2pos[nid] = tail;
					tail++;
				}
			}
			curpos++;
		}


		double sum = 0.0;
		for(int j = n - 1; j >= 1; j--){
			node &item = tree[j];
			node &parent = tree[item.parent_pos];
			int len = item.len;
			sum += (double)(item.nPoints)*(double)(n - item.nPoints)*(double)len;
			parent.nPoints += item.nPoints;
		}

		double avg = (double)sum * 2.0 / (double)(n)/ (double)(n-1) ;
		printf("%.3lf\n", avg);
	}
	return 0;
}


/*#include <list>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 10111;
list<pair<int,int> > neighbors[MAXN];
int vis[MAXN] = {};

double sum = 0.0;
int n;

int dfs(int x)
{
	int num = 1;
	vis[x] = 1;
	for(list<pair<int,int> >::iterator it = neighbors[x].begin(); it != neighbors[x].end(); it++){
		int nid = it->first;
		if(!vis[nid]){
			int tmp = dfs(nid);
			num += tmp;
			sum += (double)(tmp)*(double)(n-tmp)*(double)(it->second);
		}
	}
	return num;
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		int u, v, val;
		for(int i = 0; i < n; i++){
			neighbors[i].clear();
		}
		memset(vis, 0, sizeof(vis));
		sum = 0.0;

		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v >> val;
			neighbors[u].push_back(pair<int,int>(v,val));
			neighbors[v].push_back(pair<int,int>(u,val));
		}
		dfs(0);
		printf("%.3lf\n", sum * 2.0 / (double)n / (double)(n-1));
	}
	return 0;
}
*/
