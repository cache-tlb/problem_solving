#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
const int MAXN = 256;
int main()
{
	string s;
	stringstream ss;
	while(getline(cin, s)){
		//if(s=="") break;
		int n = 0;
		double xa[MAXN] = {}, xb[MAXN] = {}, ya[MAXN] = {}, yb[MAXN] = {};
		for(int i = 0; i < s.length(); i++){
			if(s[i]=='('){
				n++;
				s[i] = ' ';
			}
			else if(s[i]==')' || s[i]==','){
				s[i] = ' ';
			}
		}
		ss << s;
		const char *pstr = s.c_str();
		for(int i = 0; i < n; i++){
			//sscanf(pstr,"(%lf,%lf)",&xa[i],&xb[i]);
			ss >> xa[i] >> xb[i]; 
		}
		getline(cin ,s);
		for(int i = 0; i < s.length(); i++){
			if(s[i]=='(' || s[i]==')' || s[i]==','){
				s[i] = ' ';
			}
		}
		ss << s;
		for(int i = 0; i < n; i++){
			//scanf("(%lf,%lf)",&ya[i],&yb[i]);
			ss >> ya[i] >> yb[i];
		}
		double p;
		scanf("%lf",&p);
		double da[MAXN] = {}, db[MAXN] = {};
		for(int i = 0; i < n; i++){
			da[i] = xa[i] - ya[i];
			db[i] = xb[i] - yb[i];
		}
		double ans = 0.0;
		for(int i = 0; i < n; i++){
			ans += pow(da[i]*da[i]+db[i]*db[i],p*0.5);
		}
		//for(int i = 0; i < n; i++){
		//	printf("(%lf,%lf) ",ya[i],yb[i]);
		//}
		//iprintf("\n");
		ans = pow(ans,1.0/p);
		printf("%lf\n",ans);
		getchar();
	}
	//cout << s << endl;
	return 0;
}
