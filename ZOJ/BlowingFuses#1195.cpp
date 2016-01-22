#include<iostream>
using namespace std;
const int MAXN = 20 + 10;
int main()
{
	int n, m, c;
	int round = 1;
	while(cin >> n >> m >> c){
		if(!n && !m && !c) break;
		bool de[MAXN] = {};
		//for(int i = 0; i < n; i++){
		//	de[i] = false;
		//}
		int a[MAXN] = {};
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int amp = 0, flag = 1, Maxmum = 0;
		for(int i = 0; i < m; i++){
			int k;
			cin >>  k;
			if(de[k]){
				amp -= a[k-1];
			}
			else{
				amp += a[k-1];
			}
			//cout << amp << endl;
			de[k] = !de[k];
			if(amp>Maxmum) Maxmum = amp;
			if(amp>c && flag){
				flag = 0;
			}
		}
		//if(round > 1) cout << endl;
		cout << "Sequence " << round << endl;
		if(!flag) cout << "Fuse was blown." << endl;
		else cout << "Fuse was not blown." << endl << "Maximal power consumption was " << Maxmum << " amperes." << endl;
		cout << endl;
		round++;
	}
	return 0;
}
