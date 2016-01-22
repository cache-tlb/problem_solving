#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN = 5001;
bool a[MAXN][MAXN] = {};
char s[MAXN] = {};
int main()
{
	int gap, start, len, cnt, end;
	while(gets(s)){
		//memset(a,0,sizeof(a));
		len = strlen(s);
		cnt = len;
		for(int i = 0; i < len; i++){
			a[i][i] = true;
		}
		//a[len-1][len-1] = true;
		for(gap = 1; gap < len; gap++){
			for(start = 0; start < len - gap; start++){
				end = start + gap;
				a[start][end] = false;
				if(s[start]==s[end]){
					if(start+1 < end-1){
						if(a[start+1][end-1]){
							a[start][end] = true;
							cnt++;
						}
					}
					else{
						a[start][end] = true;
						cnt++;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
