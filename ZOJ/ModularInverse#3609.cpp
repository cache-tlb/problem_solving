#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if(a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		int a, m;
		cin >> a >> m;
		if(gcd(a,m)!=1){
			cout << "Not Exist" << endl;
		}
		else if(m==1){
			cout << 1 << endl;
		}
		else{
			int k = 1, p = a%m;
			while(p!=1){
				k++;
				p = (p+a) % m;
			}
			cout << k << endl;
		}
	}
	return 0;
}
/*
//这题的意思就是：求一个最小的正整数x，使a乘以x对m的取余等于1对m的取余！
#include <iostream>
using namespace std;

int main()
{
	int testcase, i, a, m;
	bool flag;
	cin >> testcase;
	while (testcase--){
		cin >> a >> m;
		flag = false;
		if (m ==  1){
			cout << 1 << endl;
			continue;
		}
		else{
			for (i = 1; i <= m; i++){
				if ((a * i % m) == 1){
					cout << i << endl;
					flag = true;
					break;
				}
			}
			if (!flag)
				cout << "Not Exist" << endl;
		}
	}
}*/
