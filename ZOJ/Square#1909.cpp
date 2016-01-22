/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[20];
bool t[20];
int ok = 0;
int M;
void search(int index, int len, int count, int edge);
void NextEdge(int count, int edge)
{
	if(ok == 1) return;
	if(count == 3){
		ok = 1;
		return;
	}
	int start;
	for(int i=0; i<M; i++){
		if(t[i] == false){
			start = i;
			break;
		}
	}
	if(a[start] > edge) return;
	t[start] = true;
	search(start+1, edge-a[start], count, edge);
	t[start] = false;
}
void search(int index, int len, int count, int edge)
{
	if(ok == 1) return;
	if(count == 3){
		ok = 1;
		return;
	}
	if(len == 0){
		NextEdge(count+1, edge);
	}
	for(int i=index; i<M; i++){
		if(t[i] == false && len-a[i]>=0){
			t[i] = true;
			search(i+1, len-a[i], count, edge);
			t[i] = false;
		}
	}
}
int cmp(const void *c1, const void*c2)
{
	return *(int *)c2 - *(int *)c1;
}
int main()
{
	int N;
	scanf("%d", &N);
	while(N--){
		ok = 0;
		scanf("%d", &M);
		int sum = 0;
		for(int i=0; i<M; i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if(sum%4 != 0){
			printf("no\n");
			continue;
		}
		int edge = sum/4;
		memset(t, 0, sizeof(t));
		qsort(a, M, sizeof(int), cmp);
		NextEdge(0, edge);
		if(ok == 1) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
*/
// my own code
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 20 + 10;
const int MAXV = 10000 + 10;
int ntype = 0;
int counts[MAXN] = {};
int value[MAXN] = {};
int a[MAXV] = {};
int flag = 0;
int m = 0;
int each = 0;
void dfs(int start,int target,int cnt);
void nextperson(int cnt){
	if(cnt==m){//the money has been divided into m parts successfully
		flag = 1;
		return;
	}
	int start = 0;//start for the greatest value's rank
	for(int i = 0; i < ntype; i++){
		if(counts[i]>0){
			start = i;
			break;
		}
	}
	counts[start]--;
	dfs(start, each - value[start], cnt);
	if(flag) return;
	counts[start]++;
}
void dfs(int start,int target,int cnt)
{
	if(target==0){
		nextperson(cnt+1);
	}
	else{
		for(int i = start; i < ntype; i++){
			if(counts[i]>0 && value[i]<=target){
				counts[i]--;
				dfs(i, target-value[i], cnt);
				if(flag) return;
				counts[i]++;
			}
		}
	}//end_if(target==0)
}
int main()
{
	int t;
	m = 4;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		memset(counts,0,sizeof(counts));
		memset(a,0,sizeof(a));
		memset(value,0,sizeof(value));
		flag = 0;
		ntype = 0;
		int sum = 0;
		for(int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			sum += temp;
			a[temp]++;
		}
		for(int i = 0; i < MAXV; i++){
			if(a[i]){
				value[ntype] = i;
				counts[ntype] = a[i];
				ntype++;
			}
		}
		int maxvalue = value[ntype-1];
		if(sum%4!=0){
			cout << "no" << endl;
			continue;
		}
		each = sum/4;
		nextperson(0);
		if(flag) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}

