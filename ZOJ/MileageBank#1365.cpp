#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	string ss;
	int sum = 0;
	while(cin >> s){
		if(s=="#") break;
		else if(s=="0"){
			cout << sum << endl;
			sum = 0;
			continue;
		}
		else{
			cin >> ss;
			int mile = 0;
			char type = 0;
			cin >> mile >> type;
			if(type=='F'){
				sum += mile*2;
			}
			else if(type=='B'){
				sum += (mile+mile/2);
			}
			else if(type=='Y'){
				if(mile<500)
					sum += 500;
				else sum += mile;
			}
		}
	}
	return 0;
}
