#include<iostream>
//#include<string>
#include<cstring>
using namespace std;
const int MAXN = 12 + 10;
const int MAXV = 100 + 10;
int ntype = 0;
int counts[MAXN] = {};
int value[MAXN] = {};
int ans[MAXN] = {};
int a[MAXV] = {};
int flag = 0;
/*string itostr(int x)
{
	string ans = "";
	if(x<10){
		ans.push_back('0'+x);
	}
	else if(x<100){
		ans.push_back('0'+x/10);
		x %= 10;
		ans.push_back('0'+x);
	}
	return ans;
}*/
//void dfs(int start,int target,string exp);
/*void nextperson(int cnt,string exp){
	if(cnt==m){//the money has been divided into m parts successfully
		flag = 1;
		cout << exp << endl;
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
	dfs(start, each - value[start], cnt, exp+"+"+itostr(value[start]));
	//if(flag) return;
	counts[start]++;
}*/
void dfs(int start,int target,int len)
{
	if(target==0){
		//nextperson(cnt+1);
		//exp[exp.length()-1] = '\0';
		for(int i = 0; i < len; i++){
			if(i) cout << '+';
			cout << ans[i];
		}
		cout << endl;
		//cout << exp << endl;
		flag = 1;
		return;
	}
	else{
		for(int i = start; i < ntype; i++){
			if(counts[i]>0 && value[i]<=target){
				counts[i]--;
				ans[len] = value[i];
				dfs(i, target-value[i], len+1);
				//if(flag) return;
				counts[i]++;
			}
		}
	}//end_if(target==0)
}
int main()
{
	int sum;
	while(cin >> sum){	// sum < 1000
		memset(a,0,sizeof(a));
		memset(value,0,sizeof(value));
		memset(counts,0,sizeof(counts));
		memset(ans,0,sizeof(ans));
		ntype = 0;
		int n;
		cin >> n;		// 1 <= n <= 12
		if(sum==0) break;
		for(int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			a[temp]++;
		}
		for(int i = MAXV; i >= 0; i--){
			if(a[i]){
				value[ntype] = i;
				counts[ntype] = a[i];
				ntype++;
			}
		}
		//for(int i = 0; i < ntype;i++){
		//	cout << value[i] << ' ' << counts[i] << endl;
		//}
		cout << "Sums of " << sum << ':' << endl;
		flag = 0;
		dfs(0,sum,0);
		if(!flag) cout << "NONE" << endl;
	}
	return 0;
}
