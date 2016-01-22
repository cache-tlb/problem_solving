#include<iostream>
using namespace std;
const int MAX = 100000 + 10;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, s;
		cin >> n >> s;
		int a[MAX] = {}, sum[MAX] = {};
	    int temp = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			temp += a[i];
			sum[i] = temp;
		}
		int low = 0, high = n - 1;
		int ans = 0, flag = 0;
		while(low <= high){
			flag = 0;
			int mid = (low + high)/2;
			for(int i = mid; i < n; i++){
				if(sum[i] - sum[i-mid] >= s){
					flag = 1;
					ans = mid;
					break;
				}
			}
			if(flag) high = mid - 1;
			else low = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
