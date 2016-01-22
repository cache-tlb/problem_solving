#include<iostream>
using namespace std;
const int MAXN = 150;
int a[MAXN][MAXN] = {};
int n = 0;
int sum_col(int j, int p, int q)
{
	int ans = 0;
	for(int i = p; i <=q; i++){
		ans += a[i][j];
	}
	return ans;
}
int Max(int p1, int p2)
{
      return p1>p2?p1:p2;
}
int Max(int p1, int p2, int p3)
{
      return p1>p2 ? (p1>p3?p1:p3): (p2>p3?p2:p3);
}
int max_sum_of_sub_arr(int* p, int len)
{
      int* sum=new int[len];
      sum[0] = p[0];
      int maxSum=sum[0]>0 ? sum[0]:0;
      for(int i=1; i<len; i++)
      {
            sum[i] = Max(sum[i-1]+p[i], p[i], 0);
            maxSum = Max(maxSum, sum[i]);
      }
	  return maxSum;
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	int temp[MAXN] = {};
	int ans = a[0][0];
	for(int p = 0; p < n; p++){
		for(int q = p; q < n; q++){
			for(int j = 0; j < n; j++){
				temp[j] = sum_col(j,p,q);
			}
			int aa = max_sum_of_sub_arr(temp,n);
			if(ans<aa) ans = aa;
		}
	}
	cout << ans << endl;
	return 0;
}
