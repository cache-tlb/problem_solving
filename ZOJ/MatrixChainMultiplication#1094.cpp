#include<iostream>
#include<string>
using namespace std;

struct Matrix{
	int row,col;
};

Matrix matrices[30];
int n;

string str = "";
int curpos = 0;
int total = 0;
bool ok = true;

void matchToken(char c)
{
	if(str[curpos]==c){
		curpos++;
	}
	else{
		ok = false;
	}
}

void matchCapital()
{
	if(str[curpos]>='A' && str[curpos]<='Z'){
		curpos++;
	}
	else{
		ok = false;
	}
}

Matrix parseM()
{
	char c = str[curpos];
	matchCapital();
	int index = c - 'A';
	return matrices[index];
}

Matrix parseE()
{
	if(str[curpos]=='('){
		matchToken('(');
		Matrix m1 = parseE();
		Matrix m2 = parseE();
		matchToken(')');
		if(m1.col!=m2.row){
			ok = false;
		}
		total += m1.row*m1.col*m2.col;
		Matrix m;
		m.row = m1.row;
		m.col = m2.col;
		return m;
	}
	else if(str[curpos]>='A' && str[curpos]<='Z'){
		Matrix m = parseM();
		return m;
	}
	else{
		ok = false;
		Matrix m;
		m.row = 0;
		m.col = 0;
		return m;
	}
}

void init()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		int row, col;
		cin >> row >> col;
		matrices[c-'A'].row = row;
		matrices[c-'A'].col = col;
	}
}

int main()
{
	init();
	while(cin >> str){
		curpos = 0;
		total = 0;
		ok = true;
		parseE();
		if(ok)
			cout << total << endl;
		else
			cout << "error" << endl;
	}
	return 0;
}
