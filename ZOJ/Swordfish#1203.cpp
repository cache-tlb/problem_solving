// use Prim Algorithm
#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

const int MAXN = 150;

double x[MAXN] = {};
double y[MAXN] = {};
int n;
double ans;

inline double sqr(double x){
	return x*x;
}

void work(){
	set<int> S,T;
	S.insert(0);
	for(int i = 1; i < n; i++){
		T.insert(i);
	}
	ans = 0.0;
	while(!T.empty()){
		double min_len = 1e100;
		int pos = -1;
		for(set<int>::iterator it1 = S.begin(); it1 != S.end(); it1++){
			for(set<int>::iterator it2 = T.begin(); it2 != T.end(); it2++){
				double len = sqr(x[*it1]-x[*it2]) + sqr(y[*it1]-y[*it2]);
				if(len < min_len){
					min_len = len;
					pos = *it2;
				}
			}
		}
		//cout << min_len << endl;
		T.erase(pos);
		S.insert(pos);
		ans += sqrt(min_len);
	}
}

int main(int argc, char const *argv[])
{
	int t = 0;
	while(cin >> n){
		if(!n) break;
		t++;
		if(t>1) printf("\n");
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
		}
		work();
		printf("Case #%d:\nThe minimal distance is: %.2lf\n", t, ans);
	}
	return 0;
}
