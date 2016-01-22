#include <iostream>
#include <cstdio>
#include <map>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 10000;
const int MAXK = 27;
const int MAX = MAXK;
typedef set<pair<int,int> > MatchType;
int n, k, m;

int ans[MAXN] = {};
int submit[MAXN] = {};
int table[MAXK][MAXK] = {};
int b[MAXK][MAXK] = {};

#define inf 1000000000
#define _clr(x) memset(x,0xff,sizeof(int)*n)
 
int kuhn_munkras(int m,int n,int mat[][MAXK],int* match1,int* match2){
    int s[MAXK],t[MAXK],l1[MAXK],l2[MAXK],p,q,ret=0,i,j,k;
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

/*class HungaryMatch{
public:
	int nx, ny;
	int nMatch;
	int adj[MAX][MAX];
	int mat[MAX];
	int nNeighbor[MAX];
	bool used[MAX];

	HungaryMatch(int _nx, int _ny)
		:nx(_nx), ny(_ny),nMatch(0) {
		memset(adj, -1, sizeof(adj));
		memset(mat, -1, sizeof(mat));
		memset(nNeighbor, 0, sizeof(nNeighbor));
		memset(used, 0, sizeof(used));
	}

	void reset(){
		nMatch = 0;
		//memset(adj, -1, sizeof(adj));
		memset(mat, -1, sizeof(mat));
		memset(nNeighbor, 0, sizeof(nNeighbor));
		memset(used, 0, sizeof(used));
	}

	void add_edge(int xval, int yval){
		adj[xval][nNeighbor[xval]++] = yval;
	}

	bool crosspath(int k){
		// k belongs to set X
		for (int i = 0; i < nNeighbor[k]; i++){
			int j = adj[k][i];	// j belongs to set Y
			if (!used[j]) {
				used[j] = true;
				if (mat[j] == -1 || crosspath(mat[j])) {
					mat[j] = k;
					return true;
				}
			}
		}
		return false;
	}

	void hungary() {
		for (int i = 0; i < nx; i++) {
			if (crosspath(i)) nMatch++;
			memset(used,0,sizeof(used));
		}
	}

};

void best_match() {
	HungaryMatch m(k, k);
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			if(table[i][j]==0){
				m.add_edge(i,j);
			}
		}
	}
	m.hungary();
	while(m.nMatch != k){

	}
}

bool operator < (const pair<int,int> &a, const pair<int,int> &b){
	return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

bool eq(set<int> &a, set<int> &b){
	for(set<int>::iterator it = a.begin(); it != a.end(); it++){
		if(b.count(*it)==0) return false;
	}
	for(set<int>::iterator it = b.begin(); it != b.end(); it++){
		if(a.count(*it)==0) return false;
	}
	return true;
}

void diff(set<int> &a, set<int> &b, set<int> &res){
	for(set<int>::iterator it = a.begin(); it != a.end(); it++){
		if(!b.count(*it)){
			res.insert(*it);
		}
	}
}*/

/*void Hungary(int b[MAXK][MAXK], MatchType &match)
{
	// init_match
	for(int x = 0; x < k; x++){
		//bool ok = false;
		for(int y = 0; y < k; y++){
			if(b[x][y]) continue;
			bool ok = true;
			for(MatchType::iterator it = match.begin(), it != match.end(); it++){
				if(it->second == y){
					ok = false;
					break;
				}
			}
			if(ok){
				match.insert(pair<int,int>(x,y));
				break;
			}
		}
	}
	int xlabel[MAXK] = {};
	int ylabel[MAXK] = {};
	for(MatchType::iterator it = match.begin(), it != match.end(); it++){
		xlabel[it->first] = 1;
		ylabel[it->second] = 1;
	}

	bool con2 = true;
	while(con2){
		con2 = false;
		bool allnonz = true;
		int zpos = 0;
		for(int i = 0; i < k; i++){
			if(x[i] == 0){
				zpos = i;
				allnonz = false;
				break;
			}
		}
		if(allnonz) return;
		set<int> U; U.insert(zpos);
		set<int> V;
		set<int> Gamma;
		for(set<int>::iterator it = U.begin(); it != U.end(); it++){
			//
			for(int j = 0; j < k; j++){
				if(b[*it][j]) continue;
				Gamma.insert(j);
			}
		}
		bool con3 = true;
		while(con3){
			con3 = false;
			if(eq(Gamma,V)) {
				xlabel[zpos] = 2;
				con2 = true;
				break;
			}
			bool hasyi = false;
			int yi = -1;
			for(set<int>::iterator it = Gamma.begin(); it != Gamma.end(); it++){
				if(V.count(*it)==0){
					hasyi = true;
					yi = *it;
					break;
				}
			}
			if(ylabel[yi]==1){
				for(MatchType::iterator it = match.begin(); it != match.end(); it++){
					if(it->second==yi){
						U.insert(it->first);
						V.insert(it->second);
						break;
					}
				}
			}
			else{
				
			}
		}
	}
}*/

int main()
{
	int T;
	cin >> T;
	while(T--){
		//n (0 < n < 10000), k (0 < k < 27) m (0 < m < 30)
		cin >> n >> k >> m;
		int ans_map[MAXK] = {};
		memset(ans_map, -1, sizeof(ans_map));
		int anslable = 0;
		for(int i = 0; i < n; i++){
			char x;
			cin >> x;
			int index = x-'A';
			if(ans_map[index] < 0){
				ans_map[index] = anslable;
				ans[i] = anslable;
				anslable++;
			}
			else{
				ans[i] = ans_map[index];
			}
		}
		while(m--){
			int sub_map[MAXK] = {};
			memset(sub_map, -1, sizeof(sub_map));
			int sublable = 0;
			for(int i = 0; i < n; i++){
				char x;
				cin >> x;
				int index = x-'A';
				if(sub_map[index] < 0){
					sub_map[index] = sublable;
					submit[i] = sublable;
					sublable++;
				}
				else{
					submit[i] = sub_map[index];
				}
			}
			memset(table, 0, sizeof(table));
			//memset(mask, 0, sizeof(mask));
			for(int i = 0; i < n; i++){
				table[submit[i]][ans[i]]++;
			}
			int m1[MAXK], m2[MAXK];
			int sum = kuhn_munkras(k,k,table,m1,m2);

			double sim = (double)sum/(double)n;
			printf("%.4f\n", sim);
		}
	}
	return 0;
}
