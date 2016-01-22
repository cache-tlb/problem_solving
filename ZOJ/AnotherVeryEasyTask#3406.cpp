#include<iostream>
#include<stdio.h>
//#include<fstream>
using namespace std;
int main()
{
	char c,pre;
	int cnt = 0;
	//ofstream cout("out.txt");
	while((c = getchar())!=EOF){
		if(!isalpha(c)){
			if(cnt>2)cout<<cnt-2<<pre;
			else if(cnt==2) cout << pre;
			cout << c;
			cnt = 0;
		}
		else{
			pre = c;
			if(cnt==0) cout << c;
			cnt++;
		}
	}
	return 0;
}
