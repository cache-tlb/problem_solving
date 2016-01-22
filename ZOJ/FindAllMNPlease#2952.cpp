#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
	vector<double> vd;
	map<double,int> md;
	for(int N = 2; N <=46340; N++){
		for(int M = 2; M <=31; M++){
			double temp = pow(double(N),double(M));
			if(temp>=2147483648)
				break;
			else{
				if(md[temp]) continue;
				else{
					vd.push_back(temp);
					md[temp] = 1;
				}
			}
		}
	}
	sort(vd.begin(),vd.end());
	for(int i = 0; i < vd.size(); i++)
		printf("%d\n",(int)vd[i]);
	return 0;
}
