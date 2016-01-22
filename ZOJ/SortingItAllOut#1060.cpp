/*#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
const int MAXN = 26;
const int MAXM = 26*26;
struct tuple{
	int  l,r;
};
int vis[MAXN] = {};
int main()
{
	int n, m;
	string s;
	while(cin >> n >> m){
		if(!n && !m) break;
		memset(vis, 0, sizeof(vis));
		tuple t[MAXM] = {};
		for(int i = 0; i < m; i++){
			cin >> s;
			t[i].l = s[0] - 'A';
			t[i].r = s[2] - 'A';
		}
		//for(int i = 0; i < m; i++)
		//	cout << t[i].l << ' ' << t[i].r << endl;
		int cnt = 0;
		int ans[MAXN] = {};
		int status = -1;
		while(cnt < n){
			int temp[MAXN] = {};
			for(int i = 0; i < m; i++){
				int left = t[i].l;
				if(!vis[left]) temp[left]++;
			}
			int zero = 0, zpos = 0;
			for(int i = 0; i < n; i++){
				if(temp[i]){
					zpos = i;
					zeros++;
				}
			}
			if(zpos>1){
				status = 1;	//invalid input: multity result
				break;
			}
			else if(zpos<1){
				status = 2;	//invalid input: no answer
				break;
			}
			else{
				ans[cnt++] = zpos;
				vis[zpos] = 1;
			}
		}
		if(status==)
	}
	return 0;
}*/
#include <cstdio>
#include <cstring>
char adj[26][26];
int rowVal[26], columnVal[26];
int reverse_order[26];

void warshall(int num) /* warshall algorithm : to calculate the transitive closure */
{
	int i, j, k;
	for (j = 0; j < num; j++){
		if (!columnVal[j]) continue;
		for (i = 0; i < num; i++) if (adj[i][j] && i!=j)
				for (k = 0; k < num; k++)
					if (!adj[i][k] && (adj[i][k] |= adj[j][k])){
						rowVal[i]++;
						columnVal[k]++;
					}
	}
}

int has_loop(int num) /* based on the warshall algorithm, to check loop existence*/
{
	int i;
	for (i = 0; i < num; i++){
		if (adj[i][i])
			return 1;
	}
	return 0;    
}

int order(int num)
{
	int i, sum = 0;
	for (i = 0; i < num; i++) sum += rowVal[i];

	if (sum != (num-1)*num/2)
		return 0;
	else{
		for (i = 0; i < num; i++)
			reverse_order[rowVal[i]] = i;
		return 1;
	}
}

int main()
{
	int i, j, lnum, rnum, loop, ordered;
	char lc, rc;
	while (scanf("%d%d", &lnum, &rnum) == 2 && lnum){
		memset(adj, 0, sizeof(char)*26*26);
		memset(rowVal, 0, sizeof(int)*26);
		memset(columnVal, 0, sizeof(int)*26);
		memset(reverse_order, 255, sizeof(int)*26);
		loop = ordered = 0;

		for (i = 0; i < rnum; i++){
			getchar();
			lc = getchar();
			getchar();
			rc = getchar(); 
			if (loop || ordered) continue;
			if (!adj[lc-'A'][rc-'A'] && (adj[lc-'A'][rc-'A'] = 1)){
				rowVal[lc-'A']++;    /* total number of '1's in a row */
				columnVal[rc-'A']++; /* total number of '1's in a column used in the warshall algorithm*/
			}
			warshall(lnum); 
			if (has_loop(lnum)){
				loop = 1;
				printf("Inconsistency found after %d relations.\n", i+1);
			}
			if (order(lnum)){
				ordered = 1;
				printf("Sorted sequence determined after %d relations: ", i+1);
				for (j = lnum-1; j >= 0; j--)
					printf("%c", reverse_order[j]+'A');
				printf(".\n");
			}
		}
		if (!loop && !ordered){
			printf("Sorted sequence cannot be determined.\n");
		}
	}
	return 0;
}
