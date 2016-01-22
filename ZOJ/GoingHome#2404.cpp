#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>

using namespace std;

const int MAXN = 200;

struct point {
	int x,y;
	point(){}
	point(int _x,int _y){x=_x;y=_y;}
};

int n, m;
int table[MAXN][MAXN] = {};
int nMan, nHouse;

point man[MAXN];
point house[MAXN];

#define inf 1000000000
#define _clr(x) memset(x,0xff,sizeof(int)*n)

inline int my_abs(int x){
	return x < 0 ? -x : x;
}
 
int kuhn_munkras(int m,int n,int mat[][MAXN],int* match1,int* match2){
    int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k;
    for (i=0;i<m;i++)
        for (l1[i]=-inf,j=0;j<n;j++)
            l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
    for (i=0;i<n;l2[i++]=0);
    for (_clr(match1),_clr(match2),i=0;i<m;i++){
        for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
            for (k=s[p],j=0;j<n&&match1[i]<0;j++)
                if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
                    s[++q]=match2[j],t[j]=k;
                    if (s[q]<0)
                        for (p=j;p>=0;j=p)
                            match2[j]=k=t[j],p=match1[k],match1[k]=j;
                }
        if (match1[i]<0){
            for (i--,p=inf,k=0;k<=q;k++)
                for (j=0;j<n;j++)
                    if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
                        p=l1[s[k]]+l2[j]-mat[s[k]][j];
            for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
            for (k=0;k<=q;l1[s[k++]]-=p);
        }
    }
    for (i=0;i<m;i++)
        ret+=mat[i][match1[i]];
    return ret;
}

int main(int argc, char const *argv[])
{
	int tmp1[MAXN]={}, tmp2[MAXN]={};
	while(cin >> n >> m){
		if(m==0 && n==0) break;
		string line;
		nMan = 0;
		nHouse = 0;
		for(int i = 0; i < n; i++){
			cin >> line;
			for(int j = 0; j < m; j++){
				if(line[j]=='m'){
					point p(j,i);
					man[nMan++] = p;
				}
				else if(line[j]=='H'){
					point p(j,i);
					house[nHouse++] = p;
				}
			}
		}
		for(int i = 0; i < nMan; i++){
			point man_pos = man[i];
			for(int j = 0; j < nHouse; j++){
				point house_pos = house[j];
				table[i][j] = - my_abs(man_pos.x - house_pos.x) - my_abs(man_pos.y - house_pos.y);
			}
		}
		int ans = kuhn_munkras(nMan,nHouse,table,tmp1,tmp2);
		cout << -ans << endl;
	}
	return 0;
}
