//本来就是一道简单题，但是没有很好的理解题目，将重复的字符给去掉，所以一直都是WA！
//下面参考了别人的代码写出了的！囧！
#include "iostream"
#include "string"
using namespace std;

string str[25];

int main()
{
	int testcase, i, j, k, time;
	cin >> testcase;
	while (testcase--)
	{
		cin >> time;
		for (i = 0; i < time; i++)
			cin >> str[i];
		for (i = 1; i < time; i++)
			for (j = 0; j < 12; j++)
			{
				for (k = 0; k < 12; k++)
					if (str[0][j] == str[i][k])
						break;
				if (k == 12)
					str[0][j] = '#';
				else
					str[i][k] = '#';
			}

		for (i = 65; i <= 91; i++)
			for (j = 0; j < 12; j++)
			{
				if (str[0][j] == i)
					cout << str[0][j];
			}
			cout << endl;
	}
}

