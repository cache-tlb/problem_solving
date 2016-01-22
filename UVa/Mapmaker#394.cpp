#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int MAXD = 11;

struct info{
	int L[MAXD];
	int U[MAXD];
	int C[MAXD];
	int D;
	int size;
	int base;
	string name;
};
int main()
{
	int n,m;
	cin >> n >> m;
	vector<info> vinfo;
	for(int i = 0; i < n; i++){
		info in;
		cin >> in.name >> in.base >> in.size >> in.D;
		for(int j = 1; j <= in.D; j++){
			cin >> in.L[j] >> in.U[j];
		}
		in.C[in.D] = in.size;
		for(int j = in.D-1; j >= 1; j--){
			in.C[j] = in.C[j+1]*(in.U[j+1]-in.L[j+1]+1);
		}
		in.C[0] = in.base;
		for(int j = 1; j <= in.D; j++){
			in.C[0] -= in.C[j]*in.L[j];
		}
		vinfo.push_back(in);
	}
	while(m--){
		string name;
		cin >> name;
		int pos = -1;
		for(int i = 0; i < n; i++){
			if(vinfo[i].name==name){
				pos = i;
				break;
			}
		}
		if(pos==-1) continue;
		int lamda = vinfo[pos].C[0];
		int temp[MAXD];
		for(int i = 1; i <= vinfo[pos].D; i++){
			cin >> temp[i];
			lamda += temp[i]*vinfo[pos].C[i];
		}
		cout << name << '[';
		int first = 1;
		for(int i = 1; i <= vinfo[pos].D; i++){
			if(first) first = 0;
			else cout << ", ";
			cout << temp[i];
		}
		cout << "] = " << lamda << endl;
	}
	return 0;
}
