#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define size 50
#define Max 0x1fffffff
int cap[size][size],s,t,n;
int queue[size],head,tail, Flow,prev[size];
bool findload()      //bfs找增广路径
{
	int i, tmp;
	memset(prev,-1,sizeof(prev));
	head = tail = 0;
	queue[tail++] = s;
	prev[s] = s;
	while(head < tail){
		tmp = queue[head++];
		for(i = 0; i < n; i++)
			if(prev[i] == -1 && cap[tmp][i] > 0){
				prev[i] = tmp;
				if (i == t) return true;
				queue[tail++] = i;
			}
	}
	return false;
}
int maxflow()
{
	Flow = 0;
	while(findload()){
		int min = Max;
		for(int i = t; i != s; i = prev[i])  //增广路径中的最小可通过流
			if(min > cap[prev[i]][i]) min = cap[prev[i]][i];
		for(int i = t; i != s; i = prev[i]){//调整路径上的流
			cap[prev[i]][i] -= min;
			cap[i][prev[i]] += min;
		}
		Flow += min;   //最大流累加
	}
	return Flow;
}
int a, b, jeo[16], cnt;
int main()
{
	while(scanf("%d%d", &a, &b) != EOF){
		memset(cap, 0, sizeof(cap));
		s = 0, t = a + a + 1; n = t + 1;
		for(int i = 1; i <= a; i++){
			cap[i][i + a] = 1;
		}
		while(b--){
			int tmp; scanf("%d", &tmp);
			for(int i = 0; i < tmp; i++)scanf("%d", &jeo[i]);
			sort(jeo, jeo + tmp);
			cap[s][jeo[0]] = 1;cap[jeo[tmp - 1]][t] = 1;
			for(int i = 0; i < tmp - 1; i++){
				cap[jeo[i] + n][jeo[i + 1]] = 1;
			}
		}
		printf("%d\n", maxflow());
	}
	return 0;
}

