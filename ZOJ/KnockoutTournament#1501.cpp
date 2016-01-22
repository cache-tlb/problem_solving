#include <iostream>
#include <cstdio>
using namespace std;

int a[1025] = {};

int main()
{
	int n;
	a[0] = -1;
	int first = 1;
	while(scanf("%d", &n)){
		if(!n) break;
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		int num = 1 << n;
		int start = num;
		int k = num;
		for(int i = 0; i < k; i++){
			a[start + i] = i;
		}
		while(k){
			k >>= 1;
			start >>= 1;
			for(int i = 0; i < k; i++){
				int x;
				cin >> x;
				a[start + i] = x - 1;
			}
		}
		int m;
		cin >> m;
		while(m--){
			int q;
			cin >> q;
			q--;
			int ub = 1, pos = q + num, level = 0;
			while(a[pos] == a[pos/2]){
				pos /= 2;
				level ++;
			}
			while(a[pos] != a[1]){
				ub++;
				pos /= 2;
				while(a[pos] == a[pos/2]){
					pos /= 2;
				}
			}
			int lb = num - (1 << level) + 1;
			//cout << ub << ' ' << lb << endl;
			printf("Player %d can be ranked as high as %d or as low as %d.\n", q + 1, ub, lb);
		}

	}
	return 0;
}
