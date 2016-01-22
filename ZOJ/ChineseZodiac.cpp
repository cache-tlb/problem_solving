#include<iostream>
#include<string>
using namespace std;
string s[] = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", 
	          "Ram", "Monkey", "Rooster", "Dog", "Pig"};
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << s[(600-n+4)%12] << endl;
	}
	return 0;
}
