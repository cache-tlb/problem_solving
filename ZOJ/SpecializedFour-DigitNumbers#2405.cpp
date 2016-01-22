#include<iostream>
using namespace std;
int sum(int x, int base){
	int ans = 0;
	while(x){
		ans += x%base;
		x /= base;
	}
	return ans;
}
int main()
{
	for(int i = 2992; i <= 9999; i++){
		int s = sum(i,10);
		if(s==sum(i,12) && s==sum(i,16))
			cout << i << endl;
	}
	return 0;
}
