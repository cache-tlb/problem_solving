#include<iostream>
#include<vector>
using namespace std;
bool palindrom(int x, int k)
{
	vector<int> rep;
	while(x){
		rep.push_back(x%k);
		x /= k;
	}
	int n = rep.size();
	for(int i = 0; i < n; i++){
		if(rep[i]!=rep[n-1-i]) return false;
	}
	return true;
}
int main()
{
	int n;
	while(cin >> n){
		if(!n) break;
		vector<int> basis;
		for(int k = 2; k <= 16; k++){
			if(palindrom(n,k)) basis.push_back(k);
		}
		cout << "Number " << n << " is ";
		if(basis.size()==0)
			cout << "not a palindrom" << endl;
		else{
			cout << "palindrom in basis";
			for(int i = 0; i < basis.size(); i++)
				cout << ' ' << basis[i];
			cout << endl;
		}
	}
	return 0;
}
