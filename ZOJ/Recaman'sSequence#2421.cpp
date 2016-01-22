#include<iostream>
#include<map>
using namespace std;
const int MAXN = 500001;
int table[MAXN] = {};
map<int,int> mi;
void Init()
{
	table[0] = 0;
	for(int i = 1; i < MAXN; i++){
		int temp = table[i-1] - i;
		if(temp>0 && !mi[temp]){
			table[i] = temp;
			mi[temp] = 1;
		}
		else{
			table[i] = table[i-1] + i;
			mi[table[i]] = 1;
		}
	}
}
int main()
{
	Init();
	int k;
	while(cin >> k){
		if(k==-1) break;
		else{
			cout << table[k] << endl;
		}	
	}
	return 0;
}
